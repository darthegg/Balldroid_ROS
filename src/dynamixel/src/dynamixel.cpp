#include "dynamixel_sdk.h"

#include <iostream>
#include "ros/ros.h"
#include "balldroid_msgs/Dynamixel.h"


/** Definitions **/
// Control table address
#define ADDR_MX_TORQUE_ENABLE           24                  // Control table address is different in Dynamixel model
#define ADDR_MX_GOAL_POSITION           30
#define ADDR_MX_PRESENT_POSITION        36

// Protocol version
#define PROTOCOL_VERSION                1.0                 // See which protocol version is used in the Dynamixel

// Default setting
#define BAUDRATE                        57600    //Please consider changing 1115200
#define DEVICENAME                      "/dev/ttyUSB1"      // Check which port is being used on your controller
                                                            // ex) Windows: "COM1"   Linux: "/dev/ttyUSB0" Mac: "/dev/tty.usbserial-*"

#define TORQUE_ENABLE                   1                   // Value for enabling the torque
#define TORQUE_DISABLE                  0                   // Value for disabling the torque


#define ESC_ASCII_VALUE                 0x1b


using namespace std;

/* Global variables */
dynamixel::PortHandler *portHandler;
dynamixel::PacketHandler *packetHandler;

const int DXL_ID[] = {1, 16};


uint8_t dxl_error = 0;
int dxl_comm_result = COMM_TX_FAIL; 


void PosCallback(const balldroid_msgs::Dynamixel::ConstPtr& msg){
	dxl_comm_result = packetHandler->write2ByteTxRx(portHandler, DXL_ID[msg->id], ADDR_MX_GOAL_POSITION, msg->target_pos, &dxl_error);
    if (dxl_comm_result != COMM_SUCCESS)
    {
        ROS_ERROR("%s\n", packetHandler->getTxRxResult(dxl_comm_result));
    }
    else if (dxl_error != 0)
    {
        ROS_ERROR("%s\n", packetHandler->getRxPacketError(dxl_error));
    }
}


bool InitDynamixel(){
    // Initialize PortHandler instance
    portHandler = dynamixel::PortHandler::getPortHandler(DEVICENAME);

    // Initialize PacketHandler instance
    packetHandler = dynamixel::PacketHandler::getPacketHandler(PROTOCOL_VERSION);

    //Ope port
    if(!portHandler->openPort()){
        ROS_ERROR("Failed to open the port!\n");
        return false;

    }

    // Set port baudrate -> if baudrate is not matched
    if(!portHandler->setBaudRate(BAUDRATE))
    {
        ROS_ERROR("Failed to change the baudrate!\n");
        return false;
    }

    // Enable Dynamixel Torque
    dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, DXL_ID[0], ADDR_MX_TORQUE_ENABLE, TORQUE_ENABLE, &dxl_error);
    if (dxl_comm_result != COMM_SUCCESS)
    {
        ROS_INFO("%s\n", packetHandler->getTxRxResult(dxl_comm_result));
    }
    else if (dxl_error != 0)
    {
        ROS_ERROR("%s\n", packetHandler->getRxPacketError(dxl_error));
    }

    // Enable Dynamixel Torque
    dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, DXL_ID[1], ADDR_MX_TORQUE_ENABLE, TORQUE_ENABLE, &dxl_error);
    if (dxl_comm_result != COMM_SUCCESS)
    {
        ROS_INFO("%s\n", packetHandler->getTxRxResult(dxl_comm_result));
    }
    else if (dxl_error != 0)
    {
        ROS_ERROR("%s\n", packetHandler->getRxPacketError(dxl_error));
    }

}


int main(int argc, char** argv){
    /* Dynamixel initialize */

    InitDynamixel();

    /* Ros initialize */
    ros::init(argc, argv, "dynamixel");
    ros::NodeHandle n;
    ros::Publisher dyn_pub[2] = {n.advertise<balldroid_msgs::Dynamixel>("/dynamixel/pos/0", 100), n.advertise<balldroid_msgs::Dynamixel>("/dynamixel/pos/1", 100)};
    ros::Subscriber dyn_sub = n.subscribe("/dynamixel/cmd", 100, PosCallback);

    ros::Rate loop_rate(25);//100hz


    /* Main Loop */
    while(ros::ok()){
        balldroid_msgs::Dynamixel msg;

        //Publish ros position
        for(int id=0;id<2;id++){
            uint16_t encoder = 0;
            dxl_comm_result = packetHandler->read2ByteTxRx(portHandler, DXL_ID[id], ADDR_MX_PRESENT_POSITION, &encoder, &dxl_error);
            if (dxl_comm_result != COMM_SUCCESS)
            {
                ROS_ERROR("%s\n", packetHandler->getTxRxResult(dxl_comm_result));
                return false;
            }
            else if (dxl_error != 0)
            {
                ROS_ERROR("%s\n", packetHandler->getRxPacketError(dxl_error));
                return false;
            }

            msg.id = id;
            msg.current_pos = encoder;
            //msg.target_pos = gtarget_pos;

            dyn_pub[id].publish(msg);
        }

        ros::spinOnce();
        loop_rate.sleep();
    }


    /* ROS disconnect */ 
    dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, DXL_ID[0], ADDR_MX_TORQUE_ENABLE, TORQUE_DISABLE, &dxl_error);
    dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, DXL_ID[1], ADDR_MX_TORQUE_ENABLE, TORQUE_DISABLE, &dxl_error);

    if (dxl_comm_result != COMM_SUCCESS)
    {
        printf("%s\n", packetHandler->getTxRxResult(dxl_comm_result));
    }
    else if (dxl_error != 0)
    {
        printf("%s\n", packetHandler->getRxPacketError(dxl_error));
    }

    // Close port
    portHandler->closePort();
}


