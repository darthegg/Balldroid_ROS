#include <iostream>
#include <unistd.h>
#include <sstream>

#include "epos/EposCmd.h"

#include "ros/ros.h"
#include "balldroid_msgs/Encoder.h"
#include "balldroid_msgs/MoveWheel.h"

#include <thread>
#include <queue>

#define NO_WHEEL 0

using namespace std;

/* global variables  */
queue<long> w_queue;
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
    
    w_queue.push(vel);
}

void EposThread(Epos epos){
    unsigned int ulErrorCode = 0;
    int lResult = MMC_FAILED;

    while(isRun){
        while(!w_queue.empty()){

            ros::Duration delta_t = ros::Time::now() - start_time;
            double delta_t_sec = delta_t.toSec();
            ROS_INFO("CALLTIME -> %f\n", delta_t_sec);

            start_time = ros::Time::now();

            long vel = w_queue.front();
            w_queue.pop();

            if((lResult = epos.MoveWithVelocity(vel, ulErrorCode))!=MMC_SUCCESS){
                //Add Fail logging
                cerr<<"Fail to move device -> " << NO_WHEEL << endl;
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
    Epos epos = Epos(NO_WHEEL);

    //Log_Info Setting
    epos.SetLogger(LogInfo);

    if((lResult = epos.OpenDevice(&ulErrorCode))!=MMC_SUCCESS){
        //Add Fail logging
        cerr<<"Fail to open device -> " << NO_WHEEL << endl;
    }

    if((lResult = epos.SetVelocityProfile(0,0,ulErrorCode))!=MMC_SUCCESS){
        //Add Fail logging
        cerr<<"Fail to open device -> " << NO_WHEEL << endl;
    }


    //ROS Initialize
    ros::init(argc, argv, "epos_left");


    ros::NodeHandle n;
    
    ros::Publisher enc_pub = n.advertise<balldroid_msgs::Encoder>("/epos/enc/left", 10);
    ros::Publisher vel_pub = n.advertise<balldroid_msgs::Encoder>("/epos/vel/left", 10);

    ros::Subscriber motor_sub = n.subscribe("/epos/move_wheel/left",100, WheelCallback);
    ros::Rate loop_rate(100); //100hz, 10ms

    isRun = true;

    //EPOS Thread
    thread epos_thread(EposThread, epos);



    ros::ok();
    ros::Time start_time = ros::Time::now();

    ros::spin();

    while(ros::ok())
    {
        balldroid_msgs::Encoder msg;
        msg.header.stamp = ros::Time::now();

        int pos = 0, vel=0;
        epos.GetPosition(&pos, ulErrorCode);
        epos.GetVelocity(&vel, ulErrorCode);
        msg.data = pos;
        enc_pub.publish(msg);

        msg.data = vel;
        vel_pub.publish(msg);
    
        ros::spinOnce();

        loop_rate.sleep();
    }

    isRun = false;
    epos_thread.join();

    if((lResult = epos.CloseDevice(&ulErrorCode))!=MMC_SUCCESS){
        //Add Fail logging
        cerr<<"Fail to close device -> " << NO_WHEEL << endl;
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


