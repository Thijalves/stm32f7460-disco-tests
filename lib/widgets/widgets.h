#include <mbed.h>
#include "displayUtilities.h"

#define DISPLAY_HEIGHT 272
#define DISPLAY_WIDTH 480

class Image{
    private:
        int posX;
        int posY;
        int size;
        uint8_t* source;
    public:
        Image(int posX, int posY, int size, uint8_t* source);
        void draw();
};

class Button{
    private:
        int posX;
        int posY;
        int width;
        int height;
        std::function<void()> pressed;
    public:
        Button(int posX, int posY, int width, int height);
        bool isPressed(TS_StateTypeDef* TS_State);
        void draw();
};

// class ImgTxtButton{
//     private:
//         int posX;
//         int posY;
//         int width;
//         int height;
//         uint8_t *text;
//     public:
//         ImgTxtButton(int posX, int posY, int width, int height, uint8_t* text);
//         bool isPressed(TS_StateTypeDef* TS_State);
//         void draw();
// };
