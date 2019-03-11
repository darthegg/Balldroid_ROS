#include <iostream>
#include <unistd.h>

#include "epos/EposCmd.h"

#include "ros/ros.h"
#include "balldroid_msgs/Encoder.h"
#include "balldroid_msgs/MoveWheel.h"

#include <thread>
#include <queue>


using namespace std;

/* global variables  */
queue<long> w_queue[2];
bool isRun = false;

ros::Time start_time;

void WheelCallback(const balldroid_msgs::MoveWheel::ConstPtr& msg){
    if(!isRun) return;

    
    unsigned int ulErrorCode = 0;
    int lResult = MMC_FAILED;

    //Direction -> please check if we use - value in vel
    long vel = msg->velocity;
    if(!msg->direction) vel *= -1;

    //Wheel
    int wheel = 0;
    if(msg->no_wheel){
        //LEFT Wheel
        wheel = 1;
        vel *= -1;
    }
    
    w_queue[msg->no_wheel].push(vel);
}

void EposThread(Epos* epos, int no_wheel){
    unsigned int ulErrorCode = 0;
    int lResult = MMC_FAILED;

    while(true){
        while(!w_queue[no_wheel].empty()){

            ros::Duration delta_t = ros::Time::now() - start_time;
            double delta_t_sec = delta_t.toSec();
            ROS_INFO("CALLTIME -> %f\n", delta_t_sec);

            start_time = ros::Time::now();

            long vel = w_queue[no_wheel].front();
            w_queue[no_wheel].pop();

            if((lResult = epos[1].MoveWithVelocity(vel, ulErrorCode))!=MMC_SUCCESS){
                //Add Fail logging
                cerr<<"Fail to move device -> " << no_wheel << endl;
            }

        }
        usleep(100);
    }
}


void LogInfo(string message){
    //cout<<message<<endl;
}


int main(int argc, char** argv){
    unsigned int ulErrorCode = 0;
    int lResult = MMC_FAILED;

    //Epos class initialize
    Epos epos[2] = {Epos(0), Epos(1)};

    for(int i=0;i<2;i++){
        //Log_Info Setting
        epos[i].SetLogger(LogInfo);


        if((lResult = epos[i].OpenDevice(&ulErrorCode))!=MMC_SUCCESS){
            //Add Fail logging
            cerr<<"Fail to open device -> " << i << endl;
        }

        if((lResult = epos[i].SetVelocityProfile(0,0,ulErrorCode))!=MMC_SUCCESS){
            //Add Fail logging
            cerr<<"Fail to open device -> " << i << endl;
        }
    }

    //EPOS Thread
    thread epos_thread0(EposThread, epos, 0);
    thread epos_thread1(EposThread, epos, 1);


    //ROS Initialize
    ros::init(argc, argv, "epos");

    ros::NodeHandle n;
    
    ros::Publisher enc_pub[2] = { n.advertise<balldroid_msgs::Encoder>("/epos/enc/left", 10), n.advertise<balldroid_msgs::Encoder>("/epos/enc/right", 10)};
    ros::Publisher vel_pub[2] = { n.advertise<balldroid_msgs::Encoder>("/epos/vel/left", 10), n.advertise<balldroid_msgs::Encoder>("/epos/vel/right", 10)};

    //ros::Subscriber motor_sub = n.subscribe("/epos/move_wheel/right",100, WheelCallback);
    ros::Subscriber motor_sub2 = n.subscribe("/epos/move_wheel/left",100, WheelCallback);
    ros::Rate loop_rate(100); //100hz, 10ms

    isRun = true;

    ros::ok();
    ros::Time start_time = ros::Time::now();

    ros::spin();

    while(ros::ok())
    {
        balldroid_msgs::Encoder msg;
        msg.header.stamp = ros::Time::now();

        for(int i=0;i<2;i++){
            int pos = 0, vel=0;
            unsigned int ulErrorCode = 0;
            epos[0].GetPosition(&pos, ulErrorCode);
            epos[0].GetVelocity(&vel, ulErrorCode);
            msg.data = pos;
            enc_pub[i].publish(msg);

            msg.data = vel;
            vel_pub[i].publish(msg);
        }
		
        ros::spinOnce();

        loop_rate.sleep();
    }


    for(int i=0;i<2;i++){
        if((lResult = epos[i].CloseDevice(&ulErrorCode))!=MMC_SUCCESS){
            //Add Fail logging
            cerr<<"Fail to close device -> " << i << endl;
        }
    }

    return 0;

}



/*
void WheelCallback2(const balldroid_msgs::MoveWheel::ConstPtr& msg){
    if(!isRun) return;

    unsigned int ulErrorCode = 0;
    int lResult = MMC_FAILED;

    //Direction -> please check if we use - value in vel
    long vel = msg->velocity;
    if(!msg->direction) vel *= -1;

    //Wheel
    int wheel = 0;
    if(msg->no_wheel){
        //LEFT Wheel => need to check!!
        wheel = 1;
        vel *= -1;
    }
    
    if((lResult = epos[1].MoveWithVelocity(vel, ulErrorCode))!=MMC_SUCCESS){
        //Add Fail logging
        cerr<<"Fail to open device -> " << msg->no_wheel << endl;
    }

}
*/


