#include <mbed.h>
#include "displayUtilities.h"

#define DISPLAY_HEIGHT 272
#define DISPLAY_WIDTH 480

class HUD {
    private:
        enum currentScreen{VSS, SSL, BS};
        int menuWidth = 40;
        int menuHeight = 117;
    public:
        HUD();
};

class VSSCard{
    private:
        int id;
        char team;
        double speedM1;
        double speedM2;
        double batt;
        double temp;
    public:
        VSSCard(int posX, int posY);
};


class TextButton{
    private:
        bool isPressed;
        char* text;
    public:
        TextButton(int posX, int posY, int width, int height, uint8_t* text, uint32_t color);
        void onTouch();
};