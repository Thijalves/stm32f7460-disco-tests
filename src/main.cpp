#include "mbed.h"
#include "widgets.h"
#include <string>
#include "images.h"
#include "nRF24Communication.h"

#define NRF_R_MOSI  PB_15
#define NRF_R_MISO  PB_14
#define NRF_R_SCK   PI_1
#define NRF_R_CE    PB_4
#define NRF_R_CSN   PI_2
#define NRF_R_VCC   PA_12 // MUDAR PRA 3v3

//serial printf debug
static BufferedSerial serial_port(USBTX, USBRX, 115200);
FileHandle *mbed::mbed_override_console(int fd){
    return &serial_port;
}

nRF24Communication sender(NRF_R_MOSI, NRF_R_MISO, NRF_R_SCK, NRF_R_CE, NRF_R_CSN, NRF_R_VCC, NetworkType::vss, RadioFunction::receiver);

int main()
{
  
    sender.setup(1);

    printf("configurei\n");

    ThisThread::sleep_for(1000);

        sender.printDetails();
    while (1) {

        
       

    }   
}

