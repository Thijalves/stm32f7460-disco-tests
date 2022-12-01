#include <mbed.h>
#include "displayUtilities.h"

#define DISPLAY_HEIGHT 272
#define DISPLAY_WIDTH 480


class Button{
    private:
        int posX;
        int posY;
        int width;
        int height;
        std::function<void()> pressed;
    public:
    Button(int posX, int posY, int width, int height, void (* func)());
    bool isPressed(TS_StateTypeDef* TS_State);  
};

// class VSSCard{
//     private:
//         int id;
//         char team;
//         double speedM1;
//         double speedM2;
//         double batt;
//         double temp;
//     public:
//         VSSCard(int posX, int posY);
// };