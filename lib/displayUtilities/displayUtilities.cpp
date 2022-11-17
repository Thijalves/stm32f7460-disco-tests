#include "displayUtilities.h"

void customFunctions::drawImage (int posX, int posY, uint8_t* imagem, int dimension){

    int counter = 0;

    for(int i = 3; i <= dimension*dimension*4; i += 4){

        uint32_t pixelColor = 0;
        pixelColor += (uint32_t)imagem[i] << 24;
        pixelColor += (uint32_t)imagem[i-1] << 16;
        pixelColor += (uint32_t)imagem[i-2] << 8;
        pixelColor += (uint32_t)imagem[i-3];

        // printf("(%d,%d):%lu \n",posX+(counter%dimensao),posY+(counter/dimensao), pixelColor);
        BSP_LCD_SetTextColor(pixelColor);
        if(pixelColor != (uint32_t) 0xFFc7c7c7)
            BSP_LCD_FillRect(posX+(counter%dimension),posY+(counter/dimension),1,1);
            // BSP_LCD_DrawHLine(posX+(counter%dimension), posY+(counter/dimension), 1);

        counter++;
    }
}