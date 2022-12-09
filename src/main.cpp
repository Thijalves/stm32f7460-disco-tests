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
            Rectangle logoBackground(0, 0, 180, 272, LCD_COLOR_VERDEROBOCIN);
            Image logo(48, 93, images::logo);
            Image vssButton(255, 45, images::vssButton);
            Image sslButton(255, 120, images::sslButton);
            Image settingsButton(255, 195, images::optionsButton);
            
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
                if(sslButton.isPressed(&TS_State)){
                    screenCounter = ssl;
                    break;
                }
                if(settingsButton.isPressed(&TS_State)){
                    screenCounter = settings;
                    break;
                }
            }
        }
        break;
        case vss:{
            BSP_LCD_Clear(LCD_COLOR_WHITE);
            Image vssLogo(4, 4, images::vss_blue_green);
            Rectangle leftMenu(0, 0, 40, 272, LCD_COLOR_VERDEROBOCIN);

            leftMenu.draw();
            vssLogo.draw();

            BSP_LCD_SetFont(&Font12);
            BSP_LCD_DisplayStringAt(0, 50, (uint8_t*)"Time:", LEFT_MODE);
            while (1){

            }
            break;
        }
        case ssl:
            BSP_LCD_Clear(LCD_COLOR_WHITE);
            BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
            BSP_LCD_DisplayStringAt(0, 0, (uint8_t*) "SSL Screen", LEFT_MODE);
            while (1){
                
            }
            break;
        case settings:
            BSP_LCD_Clear(LCD_COLOR_WHITE);
            BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
            BSP_LCD_DisplayStringAt(0, 0, (uint8_t*) "Options Screen", LEFT_MODE);
            while (1){
                
            }
            break;
        default:
            printf("lixo\n");
            break;
        }
       
      
        // if(botao.isPressed(&TS_State))
            
       

    }   
}

