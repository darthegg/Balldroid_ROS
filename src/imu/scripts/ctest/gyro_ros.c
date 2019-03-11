#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int main ()
{
    char data[200] = "Hello";
    int cnt = 0;
    int i = 0;

    int fd = serialOpen ("/dev/ttyUSB0", 115200) ;

    serialPuts (fd, "<sor10>\n");
    serialPuts (fd, "<sog1>\n");
    serialPuts (fd, "<soa2>\n");

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
