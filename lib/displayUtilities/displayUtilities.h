#include <mbed.h>
#include "LCD_DISCO_F746NG.h"
#include "TS_DISCO_F746NG.h"

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272

namespace displayFunctions{

    /* use sempre imagens quadradas
    preto = 0xff000001, transparente = 0xffc7c7c7
    https://lvgl.io/tools/imageconverter */
    void drawImage(int posX, int posY, uint8_t* imagem, int dimension);
    
}
