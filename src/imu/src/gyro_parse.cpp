#include <string>
#include <iostream>
#include <unistd.h>

#include <thread>
#include <queue>

#include <sstream>

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
   
    thread rcv_thread(ReceiveThread, fd);
    
    float split_value;
    float vect[9];
    stringstream ss;
    string value;

    int i = 0;
    

    while(true){
    
        while(!q.empty()){

            value = q.front();
            q.pop();
        }

       // Parsing start
        ss.clear();
        ss.str(value);

        while (ss >> split_value){

            if (ss.peek() == ','){
                ss.ignore();
            }
        
            vect[i] = split_value;
            i++;
        }

        usleep(10000);
        i = 0;

        cout << "x is " << vect[0] << endl;
        cout << "y is" << vect[1] << endl;
        cout << "z is" << vect[2] << endl;
        cout << "gx is " << vect[3] << endl;
        cout << "gy is" << vect[4] << endl;
        cout << "gz is" << vect[5] << endl;
        cout << "ax is " << vect[6] << endl;
        cout << "ay is" << vect[7] << endl;
        cout << "az is" << vect[8] << endl;
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


