#pragma once

#include <Vector2.hpp>

class Graphic{
public:
    Graphic();
    ~Graphic();
    void setScreenSize(const int screenWidth, const int screenHeight);
    void clearGraphics();
    void draw();

private:
    unsigned int width, height;
    char** data = nullptr;
    void destroyData();
};