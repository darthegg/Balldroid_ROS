#include <iostream>
#include <sstream>
#include <list>
#include <string.h>

#include "EposCmd.h"

using namespace std;


typedef int BOOL;

/* Constructor & Distroyer*/
//EPOS class constructor
Epos::Epos(int device_id){
	LogInfo("Initialize EPOS Module");

    isOpen = false;
    g_pKeyHandle = 0;

   //Set Parameters
	g_usNodeId = 1;
	g_deviceName = "EPOS4"; 
	g_protocolStackName = "MAXON SERIAL V2"; 
	g_interfaceName = "USB";

    stringstream spt;
    spt<<"USB"<<device_id;
	g_portName= spt.str(); 

	g_baudrate = 1000000; 


    PrintSettings();
}


Epos::~Epos(){
}


/* Public Functions */
//Init devices p_pErrorCode
int Epos::OpenDevice(unsigned int* p_pErrorCode)
{
	int lResult = MMC_FAILED;

	char* pDeviceName = new char[255];
	char* pProtocolStackName = new char[255];
	char* pInterfaceName = new char[255];
	char* pPortName = new char[255];

	strcpy(pDeviceName, g_deviceName.c_str());
	strcpy(pProtocolStackName, g_protocolStackName.c_str());
	strcpy(pInterfaceName, g_interfaceName.c_str());
	strcpy(pPortName, g_portName.c_str());

	LogInfo("Open device...");

	g_pKeyHandle = VCS_OpenDevice(pDeviceName, pProtocolStackName, pInterfaceName, pPortName, p_pErrorCode);

	if(g_pKeyHandle!=0 && *p_pErrorCode == 0)
	{
		unsigned int lBaudrate = 0;
		unsigned int lTimeout = 0;

		if(VCS_GetProtocolStackSettings(g_pKeyHandle, &lBaudrate, &lTimeout, p_pErrorCode)!=0)
		{
			if(VCS_SetProtocolStackSettings(g_pKeyHandle, g_baudrate, lTimeout, p_pErrorCode)!=0)
			{
				if(VCS_GetProtocolStackSettings(g_pKeyHandle, &lBaudrate, &lTimeout, p_pErrorCode)!=0)
				{
					if(g_baudrate==(int)lBaudrate)
					{
						lResult = MMC_SUCCESS;
					}
				}
			}
		}
	}
	else
	{
		g_pKeyHandle = 0;
	}

	delete []pDeviceName;
	delete []pProtocolStackName;
	delete []pInterfaceName;
	delete []pPortName;

	//Prepare Device -> idk why do this...
	if(lResult == MMC_SUCCESS){
		if((lResult = Prepare(p_pErrorCode))!=MMC_SUCCESS)
		{
			LogError("OpenDevice", lResult, *p_pErrorCode);
		}
		else{
			isOpen = true;
		}
	}

	return lResult;
}

int Epos::CloseDevice(unsigned int* p_pErrorCode)
{
	int lResult = MMC_FAILED;

	*p_pErrorCode = 0;

	LogInfo("Close device");

	if(VCS_CloseDevice(g_pKeyHandle, p_pErrorCode)!=0 && *p_pErrorCode == 0)
	{
		lResult = MMC_SUCCESS;
	}

	return lResult;
}






//Profile velocity mode
int Epos::SetVelocityProfile(unsigned int profileAcceleration, unsigned int profileDeceleration, unsigned int& p_rlErrorCode){
	int lResult = MMC_SUCCESS;
	stringstream msg;

	msg<< "Set velocity profile, node = " << deviceId;
	LogInfo(msg.str());

	if(VCS_ActivateProfileVelocityMode(g_pKeyHandle, g_usNodeId, &p_rlErrorCode) == 0)
	{
		LogError("VCS_ActivateProfileVelocityMode", lResult, p_rlErrorCode);
		lResult = MMC_FAILED;
	}

	return lResult;
}


int Epos::GetVelocityProfile(unsigned int* profileAcceleration, unsigned int* profileDeceleration, unsigned int& p_rlErrorCode){
	int lResult = MMC_SUCCESS;

	return lResult;
}


int Epos::MoveWithVelocity(long targetVelocity, unsigned int& p_rlErrorCode){
	int lResult = MMC_SUCCESS;

    /*stringstream msg;
	msg << "Move with target velocity = " << targetVelocity << " rpm, node = " << deviceId;

	LogInfo(msg.str());
    */
	if(VCS_MoveWithVelocity(g_pKeyHandle, g_usNodeId, targetVelocity, &p_rlErrorCode) == 0)
	{
		lResult = MMC_FAILED;
		LogError("VCS_MoveWithVelocity", lResult, p_rlErrorCode);
	}

	return lResult;
}






//Profile position mode
int Epos::SetPositionProfile(unsigned int profileVelocity, unsigned int profileAcceleration, unsigned int profileDeceleration, unsigned int& p_rlErrorCode){
	int lResult = MMC_SUCCESS;
	stringstream msg;

	msg << "Set position profile, node = " << deviceId;
	LogInfo(msg.str());

	if(VCS_ActivateProfilePositionMode(g_pKeyHandle, g_usNodeId, &p_rlErrorCode) == 0)
	{
		LogError("VCS_ActivateProfilePositionMode", lResult, p_rlErrorCode);
		lResult = MMC_FAILED;
	}

	return lResult;
}


int Epos::GetPositionProfile(unsigned int* profileVelocity, unsigned int* profileAcceleration, unsigned int* profileDeceleration, unsigned int& p_rlErrorCode){
	int lResult = MMC_SUCCESS;

	return lResult;
}


int Epos::MoveToPosition(long targetPosition, unsigned int& p_rlErrorCode, int Absolute, int Immediately){
	int lResult = MMC_SUCCESS;

    stringstream msg;
	msg << "Move to position = " << targetPosition << ", node = " << deviceId;

	LogInfo(msg.str());

	if(VCS_MoveToPosition(g_pKeyHandle, g_usNodeId, targetPosition, Absolute, Immediately, &p_rlErrorCode) == 0)
	{
		LogError("VCS_MoveToPosition", lResult, p_rlErrorCode);
		lResult = MMC_FAILED;
	}

	return lResult;
}



//Get motion informations
int Epos::GetPosition(int* pPosition, unsigned int& p_rlErrorCode){
    int lResult = MMC_SUCCESS;

	if(VCS_GetPositionIs(g_pKeyHandle,g_usNodeId, pPosition, &p_rlErrorCode)==0){
		LogError("VSC_GetPositionIs", lResult, p_rlErrorCode);
		lResult = MMC_FAILED;
	}

	return lResult;
}

int Epos::GetVelocity(int* pVelocity, unsigned int& p_rlErrorCode){
	int lResult = MMC_SUCCESS;

	if(VCS_GetVelocityIs(g_pKeyHandle,g_usNodeId, pVelocity, &p_rlErrorCode)==0){
		LogError("VSC_GetVelocityIs", lResult, p_rlErrorCode);
		lResult = MMC_FAILED;
	}

	return lResult;
}

int Epos::GetCurrent(short* pCurrent, unsigned int& p_rlErrorCode){
    int lResult = MMC_SUCCESS;

	if(VCS_GetCurrentIs(g_pKeyHandle,g_usNodeId, pCurrent, &p_rlErrorCode)==0){
		LogError("VSC_GetCurrentIs", lResult, p_rlErrorCode);
		lResult = MMC_FAILED;
	}

	return lResult;
}




/* Private functions */
//About logging
void Epos::LogError(string functionName, int p_lResult, unsigned int p_ulErrorCode)
{
	cerr << g_programName << ": " << functionName << " failed (result=" << p_lResult << ", errorCode=0x" << std::hex << p_ulErrorCode << ")"<< endl;
}

void Epos::LogInfo(string message)
{
    if(logger != NULL) logger(message);
	//cout << message << endl;
}


void Epos::PrintSettings()
{
    stringstream msg;

    msg << "default settings:" << endl;
    msg << "node id             = " << g_usNodeId << endl;
    msg << "device name         = '" << g_deviceName << "'" << endl;
    msg << "protocal stack name = '" << g_protocolStackName << "'" << endl;
    msg << "interface name      = '" << g_interfaceName << "'" << endl;
    msg << "port name           = '" << g_portName << "'"<< endl;
    msg << "baudrate            = " << g_baudrate;

    LogInfo(msg.str());
}


int Epos::Prepare(unsigned int* p_pErrorCode)
{
	int lResult = MMC_SUCCESS;
	BOOL oIsFault = 0;

	if(VCS_GetFaultState(g_pKeyHandle, g_usNodeId, &oIsFault, p_pErrorCode ) == 0)
	{
		LogError("VCS_GetFaultState", lResult, *p_pErrorCode);
		lResult = MMC_FAILED;
	}

	if(lResult==0)
	{
		if(oIsFault)
		{
			stringstream msg;
			msg << "clear fault, node = '" << g_usNodeId << "'";
			LogInfo(msg.str());

			if(VCS_ClearFault(g_pKeyHandle, g_usNodeId, p_pErrorCode) == 0)
			{
				LogError("VCS_ClearFault", lResult, *p_pErrorCode);
				lResult = MMC_FAILED;
			}
		}

		if(lResult==0)
		{
			BOOL oIsEnabled = 0;

			if(VCS_GetEnableState(g_pKeyHandle, g_usNodeId, &oIsEnabled, p_pErrorCode) == 0)
			{
				LogError("VCS_GetEnableState", lResult, *p_pErrorCode);
				lResult = MMC_FAILED;
			}

			if(lResult==0)
			{
				if(!oIsEnabled)
				{
					if(VCS_SetEnableState(g_pKeyHandle, g_usNodeId, p_pErrorCode) == 0)
					{
						LogError("VCS_SetEnableState", lResult, *p_pErrorCode);
						lResult = MMC_FAILED;
					}
				}
			}
		}
	}
	return lResult;
}



void Epos::SetLogger(void (*func)(std::string)){
    logger = func;
}
