#ifndef WIDGETS_H
#define WIDGETS_H

#include <U8g2lib.h>

class Widgets {
public:
    Widgets(U8G2 &display);
    void drawGauge(int x, int y, int radius, int value, int maxValue);
    void drawDonut(int x, int y, int radius, int thickness, int value, int maxValue);
    void drawLevelIndicator(int x, int y, int width, int height, int value, int maxValue);

private:
    U8G2 &u8g2;
    int mapValue(int value, int maxValue, int maxOutput);
};

#endif
