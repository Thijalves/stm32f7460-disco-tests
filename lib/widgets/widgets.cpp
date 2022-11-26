#include "widgets.h"
#include "images.h"

HUD::HUD(){
    //desenha o menu do canto inferior esquerdo
    BSP_LCD_SetTextColor(LCD_COLOR_VERDEROBOCIN);
    BSP_LCD_FillRect(0, SCREEN_HEIGHT-menuHeight, menuWidth, menuHeight);
    customFunctions::drawImage((menuWidth-32)/2, SCREEN_HEIGHT-menuHeight, images::ssl_0, 32);
    customFunctions::drawImage((menuWidth-32)/2, SCREEN_HEIGHT-menuHeight+32+5, images::vss_blue_green, 32);
    customFunctions::drawImage((menuWidth-32)/2, SCREEN_HEIGHT-menuHeight+64+10, images::gear, 32);

    //desenha a bateria
    BSP_LCD_SetBackColor(LCD_COLOR_VERDEROBOCIN);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_SetFont(&Font12);
    BSP_LCD_DisplayStringAt(420, 0, (uint8_t*)"Batt: 50%", LEFT_MODE);

    //desenha a logo do robocin
    customFunctions::drawImage(0, 0, images::logo, 64);

}

VSSCard::VSSCard(int posX, int posY){
    //retangulo
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_FillRect(posX, posY, 200, 60);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_DrawRect(posX, posY, 200, 60);
    BSP_LCD_DrawRect(posX-1, posY-1, 202, 62);
    //icone do jogador
    BSP_LCD_SetTextColor(LCD_COLOR_DARKGRAY);
    BSP_LCD_FillRect(posX + 10, posY + 15, 30, 30);
    BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
    BSP_LCD_FillRect(posX + 12, posY + 17, 26, 12);
    BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
    BSP_LCD_FillRect(posX + 12, posY + 18 + 11 + 2, 26, 12);
    //info
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_DrawVLine(posX + 45, posY, 60);
    BSP_LCD_SetFont(&Font12);
    BSP_LCD_DisplayStringAt(posX + 52, posY + 10, (uint8_t *)"ID: 1", LEFT_MODE);
    BSP_LCD_DisplayStringAt(posX + 52, posY + 20, (uint8_t *)"Mode: Game", LEFT_MODE);
    BSP_LCD_DisplayStringAt(posX + 52, posY + 34, (uint8_t *)"Batt: 100%", LEFT_MODE);
    BSP_LCD_DisplayStringAt(posX + 52, posY + 46, (uint8_t *)"Temp: 30 C", LEFT_MODE);
    // BSP_LCD_DisplayStringAt(0, 2, (uint8_t *)"M1: 100 rad/s", LEFT_MODE);
    // BSP_LCD_DisplayStringAt(0, 2, (uint8_t *)"M2: 100 rad/s", LEFT_MODE);

}

TextButton::TextButton(int posX, int posY, int width, int height, uint8_t* text, uint32_t color){
    // BSP_LCD_SetTextColor(color);
    // BSP_LCD_FillRect(posX, posY, width, height);
    // BSP_LCD_DisplayStringAt(posX, posY, text, LEFT_MODE);
}