#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int main ()
{
    int fd = serialOpen ("/dev/ttyUSB0", 115200) ;

    serialPuts (fd, "<sor10>\n");
    serialPuts (fd, "<sog1>\n");
    serialPuts (fd, "<soa2>\n");

    while(1){
        if (serialDataAvail (fd) > 0){
            while(serialDataAvail (fd)){
            
                printf("%c", serialGetchar (fd));

            }
        printf("\n");
        }

    }

      return 0;
}
