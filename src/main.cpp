#include "mbed.h"
#include "widgets.h"
#include "images.h"
#include <string>

//serial printf debug
static BufferedSerial serial_port(USBTX, USBRX, 115200);
FileHandle *mbed::mbed_override_console(int fd){
    return &serial_port;
}

int soma(int a, int b) {
    return a + b;
}

class Button{
    private:
        int posX;
        int posY;
        int width;
        int height;
        std::function<void()> pressed;
    public:
    Button(int posX, int posY, int width, int height, void (* func)()){

        this->posX = posX;
        this->posY = posY;
        this->width = width;
        this->height = height;
        BSP_LCD_SetTextColor(LCD_COLOR_VERDEROBOCIN);
        BSP_LCD_FillRect(posX, posY, width, height);
    }
    bool isPressed(TS_StateTypeDef* TS_State){
        if (!TS_State->touchDetected)
            return false;
        
        if(posX <= TS_State->touchX[0] && TS_State->touchX[0] <= posX+width)
            if(posY <= TS_State->touchY[0] && TS_State->touchY[0] <= posX+height)
                return true;
        
        return false;
        
    }
    
};

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

    // customFunctions::drawImage(200, 200, images::logo, 64);

    //setup the gome screen
    BSP_LCD_SetTextColor(LCD_COLOR_VERDEROBOCIN);
    BSP_LCD_FillRect(0, 0, 240, 272);
    customFunctions::drawImage(88, 104, images::logo, 64);
    Button botao(310, 140, 100, 40, NULL);

    while (1) {
        BSP_TS_GetState(&TS_State);

        // if(botao.isPressed(&TS_State)){
        //     printf("tocou\n");
        // }
        
        // if (TS_State.touchDetected) {
        //     if(0 <= TS_State.touchX[0] && TS_State.touchX[0] <= 0+100){
        //         printf("%d %d\n", TS_State.touchX[0], TS_State.touchY[0]);
        //     }
        // }
    }   
}

