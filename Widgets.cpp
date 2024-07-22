#include "Widgets.h"

Widgets::Widgets(U8G2 &display) : u8g2(display) {}

void Widgets::drawGauge(int x, int y, int radius, int value, int maxValue) {
    int angle = mapValue(value, maxValue, 360);
    u8g2.drawCircle(x, y, radius, U8G2_DRAW_ALL);
    u8g2.drawPie(x, y, radius, 0, angle);
}

void Widgets::drawDonut(int x, int y, int radius, int thickness, int value, int maxValue) {
    int angle = mapValue(value, maxValue, 360);
    u8g2.drawCircle(x, y, radius, U8G2_DRAW_ALL);
    u8g2.drawCircle(x, y, radius - thickness, U8G2_DRAW_ALL);
    for (int i = 0; i < angle; i += 5) {
        int x0 = x + radius * cos(i * M_PI / 180);
        int y0 = y + radius * sin(i * M_PI / 180);
        int x1 = x + (radius - thickness) * cos(i * M_PI / 180);
        int y1 = y + (radius - thickness) * sin(i * M_PI / 180);
        u8g2.drawLine(x0, y0, x1, y1);
    }
}

void Widgets::drawLevelIndicator(int x, int y, int width, int height, int value, int maxValue) {
    int level = mapValue(value, maxValue, height);
    u8g2.drawFrame(x, y, width, height);
    u8g2.drawBox(x + 1, y + height - level, width - 2, level);
}

int Widgets::mapValue(int value, int maxValue, int maxOutput) {
    return (value * maxOutput) / maxValue;
}
