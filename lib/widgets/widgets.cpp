#include "widgets.h"

//==================== Rectangle class functions ====================

Rectangle::Rectangle(int posX, int posY, int width, int height, uint32_t color){
    this->posX = posX;
    this->posY = posY;
    this->width = width;
    this->height = height;
    this->color = color;

    this->draw();
}

void Rectangle::draw(){
    BSP_LCD_SetTextColor(LCD_COLOR_VERDEROBOCIN);
    BSP_LCD_FillRect(posX, posY, width, height);
}

bool Rectangle::isPressed(TS_StateTypeDef* TS_State){

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


//==================== image class functions ====================

Image::Image(int posX, int posY, uint16_t width, uint16_t height, uint8_t* source){
    this->posX = posX;
    this->posY = posY;
    this->width = width;
    this->height = height;
    this->source = source;

    this->draw();
}

void Image::draw(){
    int counter = 0;

    // int width = this->source[0], height = this->source[1];

    for(int i = 3; i <= this->width*this->height*4; i += 4){
        uint32_t pixelColor = 0;
        pixelColor += (uint32_t)this->source[i] << 24;
        pixelColor += (uint32_t)this->source[i-1] << 16;
        pixelColor += (uint32_t)this->source[i-2] << 8;
        pixelColor += (uint32_t)this->source[i-3];

        BSP_LCD_SetTextColor(pixelColor);
        if(pixelColor != (uint32_t) 0xFFc7c7c7)
            BSP_LCD_FillRect(posX+(counter%width),posY+(counter/width),1,1);

        counter++;
    }
}

bool Image::isPressed(TS_StateTypeDef* TS_State){
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

