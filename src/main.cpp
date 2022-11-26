#include "mbed.h"
#include "widgets.h"
#include <string>

//serial printf debug
static BufferedSerial serial_port(USBTX, USBRX, 115200);
FileHandle *mbed::mbed_override_console(int fd){
    return &serial_port;
}

int main()
{
    printf("System initializing");

    //inicializa o lcd
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    BSP_LCD_Clear(LCD_COLOR_WHITE);

    //inicialica o touch
    TS_StateTypeDef TS_State;
    if (BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize())){
        printf("touchscreen int faild\n");
    } else {
        printf("touchscreen int ok\n");
    }
    
    //inits the hud
    HUD menu;

    while (1) {
        //gets the current touches
        BSP_TS_GetState(&TS_State);

        
    }
}