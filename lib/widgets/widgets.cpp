#include "widgets.h"

//==================== button class functions ====================

Button::Button(int posX, int posY, int width, int height, void (* func)()){
    this->posX = posX;
    this->posY = posY;
    this->width = width;
    this->height = height;
    BSP_LCD_SetTextColor(LCD_COLOR_VERDEROBOCIN);
    BSP_LCD_FillRect(posX, posY, width, height);
}
