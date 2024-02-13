#include "mbed.h"

Serial pc(SERIAL_TX, SERIAL_RX);

// Green LED
DigitalOut led1(LED1);
// Blue LED
DigitalOut led2(LED2);
// Red LED
DigitalOut led3(LED3);


void select_led(int l)
{
        if (l==1) {
                led1 = true;
                led2 = false;
                led3 = false;
        }
        else if (l==2) {
                led1 = false;
                led2 = true;
                led3 = false;
        }
        else if (l==3) {
                led1 = false;
                led2 = false;
                led3 = true;
        }
}


int main() {
    pc.baud(9600);
    int t=1;

    pc.printf("Start!\r\n", t);

    while(true) {
          select_led(t+1);
          pc.printf("LED %d is ON.\r\n", t+1);
          wait(0.5);
      // cycles the values of t
      // check how the modulo operation (%) works if unsure
          t=(t+1)%3;

    }
}
