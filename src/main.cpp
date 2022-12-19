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
            Rectangle* logoBackground = new Rectangle(0, 0, 180, 272, LCD_COLOR_VERDEROBOCIN);
            Image* vssButton = new Image(255, 45, 150, 50, images::vssButton);
            Image* sslButton = new Image(255, 120, 150, 50, images::sslButton);
            Image* settingsButton = new Image(255, 195, 150, 50, images::optionsButton);
            delete(logoBackground);
            delete(vssButton);
            delete(sslButton);
            delete(settingsButton);

            while (1){
                //update touch
                BSP_TS_GetState(&TS_State);

                // check buttons
                if(vssButton->isPressed(&TS_State)){
                    screenCounter = vss;
                    break;
                }
            }
        break;
        }
        case vss:{
            BSP_LCD_Clear(LCD_COLOR_WHITE);
            
            //cria objetos
            Image* topMenu = new Image(0, 0, images::vssTopMenuSize[0], images::vssTopMenuSize[1], images::vssTopMenu);
            delete(topMenu);
            
            Image(13, 58, 140, 180, images::vssCard);

            while (1){}

        break;
        }
        case ssl:
        case settings:
        default:
            printf("lixo\n");
        break;
        }
       
      
        // if(botao.isPressed(&TS_State))
            
       

    }   
}

