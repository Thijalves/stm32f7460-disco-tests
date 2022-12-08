#include "mbed.h"
#include "widgets.h"
#include <string>
#include "images.h"

//serial printf debug
static BufferedSerial serial_port(USBTX, USBRX, 115200);
FileHandle *mbed::mbed_override_console(int fd){
    return &serial_port;
}

//enum for screen manegement
enum Screens{
    home,
    vss,
    ssl,
    settings
}screenCounter;

int main()
{
    printf("------booting system------\n");
    
    //inits the display
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    printf("display OK!\n");

    //inits the touch
    TS_StateTypeDef TS_State;
    bool status = BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
    if (status != TS_OK) {
        printf("touch not OK!\n");
    } else {
        printf("touch OK!\n");
    }

    while (1) {

        switch (screenCounter) {
        case home: {
            //create screen widgets
            Image vssButton(280, 70, images::vssButton);
            Image sslButton(280, 130, images::vssButton);
            Image settingsButton(280, 190, images::vssButton);
            Image logo(58, 93, images::logo);
            Rectangle logoBackground(0,0,200, 272, LCD_COLOR_VERDEROBOCIN);
            
            //draw widgets
            logoBackground.draw();
            vssButton.draw();
            sslButton.draw();
            settingsButton.draw();
            logo.draw();


            while (1){
                //update touch
                BSP_TS_GetState(&TS_State);

                // check buttons
                if(vssButton.isPressed(&TS_State)){
                    screenCounter = vss;
                    break;
                }
            }
        }
        break;
        case vss:
            BSP_LCD_Clear(LCD_COLOR_WHITE);
            printf("vss\n");
            break;
        case ssl:
            printf("ssl\n");
            break;
        case settings:
            printf("settings\n");
            break;
        default:
            printf("lixo\n");
            break;
        }
       
      
        // if(botao.isPressed(&TS_State))
            
       

    }   
}

