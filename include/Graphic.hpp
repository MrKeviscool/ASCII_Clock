#pragma once

#include <Vector2.hpp>

struct Time;

class Graphic{
public:
    Graphic();
    Graphic(int width, int height);
    ~Graphic();
    void setScreenSize(const int screenWidth, const int screenHeight);
    void clearGraphics();
    void draw();
    void drawTime(const Time& time);
    Vector2i getSize();

private:
    int width, height;
    char** data = nullptr;
    void destroyData();
    void drawCircle();
    void drawHand(int lengthPercent, int angle, char character);
};