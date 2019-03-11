#include <string>
#include <iostream>
#include <unistd.h>

#include <thread>
#include <queue>

#include <sstream>

#include <wiringPi.h>
#include <wiringSerial.h>

#include "ros/ros.h"
#include "balldroid_msgs/Imu.h"

using namespace std;

queue<string> q;

// The function we want to execute on the new thread.
void ReceiveThread(int fd)
{
    bool isData = false;
    char str[200];
    int cnt = 0;

    while(true){

        if(serialDataAvail(fd)>0){
            char data = serialGetchar(fd);

            if(data == '*'){
                //Start Count
                isData = true;
            }
            else if(data == '\n'){
                //Stop Count
                string str_data(str);
                q.push(str_data);
                cnt = 0;
                isData = false;

                for(int i=0;i<200;i++){
                    str[i] = '\0';
                }

            }
            else{
                //Data -> save, others -> discard
                if(isData){
                    str[cnt] = data;
                    cnt++;
                }
            }
        }
        else{
            usleep(1000);
        }
    }
}


int main(int argc, char** argv)
{   
    float split_value;
    float vect[9];
    stringstream ss;
    string value;
    int i = 0;

    ros::init(argc, argv, "imu_talker");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<balldroid_msgs::Imu>("/imu_usb",30);
    ros::Rate loop_rate(100);

    int fd = serialOpen ("/dev/ttyUSB0", 115200) ;
    
    serialPuts (fd, "<sor10>\n");
    serialPuts (fd, "<sog1>\n");
    serialPuts (fd, "<soa2>\n");
    
    thread rcv_thread(ReceiveThread, fd);

    while(ros::ok()){
        
        // get data from queue
        while(!q.empty()){

            value = q.front();
            q.pop();
        }
        
        // data parsing + save in vect[i]
        ss.clear();
        ss.str(value);

        while (ss >> split_value){

            if (ss.peek() == ','){
                ss.ignore();
            }

            vect[i] = split_value;
            i++;
        } 
        
        // data save in imu msgs class
        balldroid_msgs::Imu imu;
        
        imu.euler.x = vect[0];
        imu.euler.y = vect[1];
        imu.euler.z = vect[2];
        
        imu.gyro.x = vect[3];
        imu.gyro.y = vect[4];
        imu.gyro.z = vect[5];
        
        imu.accel.x = vect[6];        
        imu.accel.y = vect[7];        
        imu.accel.z = vect[8];        
         
        // publish
        pub.publish(imu);
        ros::spinOnce();

        loop_rate.sleep();

        i = 0;
    }
}





/*
#include <stdio.h>
#include <string.h>

int main ()
{
    char data[200] = "Hello";
    int cnt = 0;
    int i = 0;

    int fd = serialOpen ("/dev/ttyUSB0", 115200) ;


    while(1){
        if (serialDataAvail (fd) > 0){
            while(serialDataAvail (fd)){
            
                data[cnt] = serialGetchar (fd);
                
                if (data[cnt] == '\n'){

                break;

                }

            cnt++;

            }
        
        printf("%s", data);
        serialFlush (fd);
        data[0] = '\0';
        cnt = 0;        

        }

    }

      return 0;
}

*/


