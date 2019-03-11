#ifndef MMC_SUCCESS
    #define MMC_SUCCESS 0
#endif

#ifndef MMC_FAILED
    #define MMC_FAILED 1
#endif

#ifndef MMC_MAX_LOG_MSG_SIZE
    #define MMC_MAX_LOG_MSG_SIZE 512
#endif


#ifndef _H_EPOSCMD_
#define _H_EPOSCMD_

#include "Definitions.h"

class Epos{
public:
	Epos(int device_id);
	~Epos();

public:
    //Init devices
	int   OpenDevice(unsigned int* p_pErrorCode);
	int   CloseDevice(unsigned int* p_pErrorCode);

    //Profile velocity mode
	int   SetVelocityProfile(unsigned int profileAcceleration, unsigned int profileDeceleration, unsigned int& p_rlErrorCode);
	int   GetVelocityProfile(unsigned int* profileAcceleration, unsigned int* profileDeceleration, unsigned int& p_rlErrorCode);
	int   MoveWithVelocity(long targetVelocity, unsigned int& p_rlErrorCode);

    //Profile position mode
	int   SetPositionProfile(unsigned int profileVelocity, unsigned int profileAcceleration, unsigned int profileDeceleration, unsigned int& p_rlErrorCode);
	int   GetPositionProfile(unsigned int* profileVelocity, unsigned int* profileAcceleration, unsigned int* profileDeceleration, unsigned int& p_rlErrorCode);
	int   MoveToPosition(long targetPosition, unsigned int& p_rlErrorCode, int Absolute=0, int Immediately=1);

    //Get motion informations
    int   GetPosition(int* pPosition, unsigned int& p_rlErrorCode);
    int   GetVelocity(int* pVelocity, unsigned int& p_rlErrorCode);
    int   GetCurrent(short* pCurrent, unsigned int& p_rlErrorCode);

    void  SetLogger(void (*func)(std::string));


private:
	void  LogError(std::string functionName, int p_lResult, unsigned int p_ulErrorCode);
	void  LogInfo(std::string message);

	int   Demo(unsigned int* p_pErrorCode);
	int   Prepare(unsigned int* p_pErrorCode);
	void  PrintSettings();

private:
    int deviceId;
    bool isOpen;

	void* g_pKeyHandle;
	unsigned short g_usNodeId;
	std::string g_deviceName;
	std::string g_protocolStackName;
	std::string g_interfaceName;
	std::string g_portName;
	int g_baudrate;

	const std::string g_programName = "EposCmd";

    void (*logger)(std::string) = NULL;

};

#endif
