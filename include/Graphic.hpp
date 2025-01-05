#pragma once

#include <Vector2.hpp>

struct Time;

class Graphic{
public:
    Graphic();
    ~Graphic();
    void setScreenSize(const int screenWidth, const int screenHeight);
    void clearGraphics();
    void draw();
    Vector2i getSize();

private:
    int width, height;
    char** data = nullptr;
    void destroyData();
    void drawCircle();
    void drawHand(int lengthPercent, int angle);
    void drawTime(const Time& time);
};