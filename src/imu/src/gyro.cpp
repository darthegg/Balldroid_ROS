#include <string>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <queue>
#include <wiringPi.h>
#include <wiringSerial.h>

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


int main()
{
    int fd = serialOpen ("/dev/ttyUSB0", 115200) ;
    
    serialPuts (fd, "<sor10>\n");
    serialPuts (fd, "<sog1>\n");
    serialPuts (fd, "<soa2>\n");
   
    // Constructs the new thread and runs it. Does not block execution.
    thread rcv_thread(ReceiveThread, fd);
    // Do other things...
    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
//    t1.join();

    while(true){
    
        while(!q.empty()){

            string value = q.front();

            q.pop();

            cout << "queue is " << value << endl;

        }

        usleep(1000);
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


