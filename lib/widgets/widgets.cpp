#include "widgets.h"
#include "images.h"

//==================== button class functions ====================

Button::Button(int posX, int posY, int width, int height, void (* func)()){
    this->posX = posX;
    this->posY = posY;
    this->width = width;
    this->height = height;
    BSP_LCD_SetTextColor(LCD_COLOR_VERDEROBOCIN);
    BSP_LCD_FillRect(posX, posY, width, height);
}

// VSSCard::VSSCard(int posX, int posY){
//     //retangulo
//     BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
//     BSP_LCD_FillRect(posX, posY, 200, 60);
//     BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
//     BSP_LCD_DrawRect(posX, posY, 200, 60);
//     BSP_LCD_DrawRect(posX-1, posY-1, 202, 62);
//     //icone do jogador
//     BSP_LCD_SetTextColor(LCD_COLOR_DARKGRAY);
//     BSP_LCD_FillRect(posX + 10, posY + 15, 30, 30);
//     BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
//     BSP_LCD_FillRect(posX + 12, posY + 17, 26, 12);
//     BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
//     BSP_LCD_FillRect(posX + 12, posY + 18 + 11 + 2, 26, 12);
//     //info
//     BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
//     BSP_LCD_DrawVLine(posX + 45, posY, 60);
//     BSP_LCD_SetFont(&Font12);
//     BSP_LCD_DisplayStringAt(posX + 52, posY + 10, (uint8_t *)"ID: 1", LEFT_MODE);
//     BSP_LCD_DisplayStringAt(posX + 52, posY + 20, (uint8_t *)"Mode: Game", LEFT_MODE);
//     BSP_LCD_DisplayStringAt(posX + 52, posY + 34, (uint8_t *)"Batt: 100%", LEFT_MODE);
//     BSP_LCD_DisplayStringAt(posX + 52, posY + 46, (uint8_t *)"Temp: 30 C", LEFT_MODE);
//     // BSP_LCD_DisplayStringAt(0, 2, (uint8_t *)"M1: 100 rad/s", LEFT_MODE);
//     // BSP_LCD_DisplayStringAt(0, 2, (uint8_t *)"M2: 100 rad/s", LEFT_MODE);

// }
