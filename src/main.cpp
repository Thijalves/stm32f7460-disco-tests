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
            Button vssButton(310, 70, 120, 32);
            Image vssImage(310, 70, 32, images::vss_blue_green);
            Image logo(78, 93, 85, images::logo);

            //draw widgets
            BSP_LCD_SetTextColor(LCD_COLOR_VERDEROBOCIN);
            BSP_LCD_FillRect(0, 0, 240, 272);
            vssButton.draw();
            vssImage.draw();
            logo.draw();

            //window 'function'
            while (1){
                //update touch
                BSP_TS_GetState(&TS_State);

                //check buttons
                // if(vssButton.isPressed(&TS_State)){
                //     screenCounter = vss;
                //     break;
                // }
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

