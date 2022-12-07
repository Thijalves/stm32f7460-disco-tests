#include "widgets.h"

//==================== image class functions ====================

Image::Image(int posX, int posY, int size, uint8_t* source){
    this->posX = posX;
    this->posY = posY;
    this->size = size;
    this->source = source;
}

void Image::draw(){
    displayFunctions::drawImage(posX, posY, source, size);
}

//==================== button class functions ====================

Button::Button(int posX, int posY, int width, int height){
    this->posX = posX;
    this->posY = posY;
    this->width = width;
    this->height = height;
}

void Button::draw(){
    BSP_LCD_SetTextColor(LCD_COLOR_VERDEROBOCIN);
    BSP_LCD_FillRect(posX, posY, width, height);
}

bool Button::isPressed(TS_StateTypeDef* TS_State){

    //check if there is a touch
    if(!TS_State->touchDetected)
        return false;
    //check X position
    if(TS_State->touchX[0] < this->posX || TS_State->touchX[0] > this->posX + this->width)
        return false;
    //check Y position
    if(TS_State->touchY[0] < this->posY || TS_State->touchY[0] > this->posY + this->height)
        return false;

    return true;
}

//==================== button img txt class functions ====================
// ImgTxtButton::ImgTxtButton(int posX, int posY, int width, int height, uint8_t* text){
//     this->posX = posX;
//     this->posY = posY;
//     this->width = width;
//     this->height = height;
//     this->text = text;    
// }

// void ImgTxtButton::draw(){
//     BSP_LCD_SetTextColor(LCD_COLOR_VERDEROBOCIN);
//     BSP_LCD_FillRect(posX, posY, width, height);
//     BSP_LCD_SetBackColor(LCD_COLOR_VERDEROBOCIN);
//     BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
//     BSP_LCD_DisplayStringAt(posX+(width/2)-1, posY+(height/3), text, LEFT_MODE);
// }

// bool ImgTxtButton::isPressed(TS_StateTypeDef* TS_State){

//     //check if there is a touch
//     if(!TS_State->touchDetected)
//         return false;
//     //check X position
//     if(TS_State->touchX[0] < this->posX || TS_State->touchX[0] > this->posX + this->width)
//         return false;
//     //check Y position
//     if(TS_State->touchY[0] < this->posY || TS_State->touchY[0] > this->posY + this->height)
//         return false;

//     return true;
// }
