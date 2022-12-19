#include <mbed.h>
#include "LCD_DISCO_F746NG.h"
#include "TS_DISCO_F746NG.h"

#define DISPLAY_HEIGHT 272
#define DISPLAY_WIDTH 480

class Image{
    private:
        int posX;
        int posY;
        uint16_t width;
        uint16_t height;
        uint8_t* source;
    public:
        Image(int posX, int posY, uint16_t width, uint16_t height, uint8_t* source);
        bool isPressed(TS_StateTypeDef* TS_State);
        void draw();
};

class Rectangle{
    private:
        int posX;
        int posY;
        int width;
        int height;
        uint32_t color;
        std::function<void()> pressed;
    public:
        Rectangle(int posX, int posY, int width, int height, uint32_t color);
        bool isPressed(TS_StateTypeDef* TS_State);
        void draw();
};


