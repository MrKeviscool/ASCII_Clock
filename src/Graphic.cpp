#include "Graphic.hpp"

#include <cstring>
#include <iostream>
#include <cmath>

Graphic::Graphic(){
    setScreenSize(40, 20);
};

Graphic::~Graphic(){
    destroyData();
}

void Graphic::setScreenSize(const int screenWidth, const int screenHeight){
    destroyData();
    width = screenWidth;
    height = screenHeight;
    data = new char*[width];
    for(int i = 0; i < width; i++)
        data[i] = new char[height];
    clearGraphics();
}

void Graphic::clearGraphics(){
    for(int i = 0; i < width; i++)
        std::memset(data[i], ' ', height);
    drawCircle();
}

void Graphic::destroyData(){
    if(!data) return;
    for(int i = 0; i < width; i++)
        delete[] data[i];
    delete[] data;
    data = nullptr;
}

void Graphic::draw(){
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++)
            std::cout << data[x][y];
        std::cout << '\n';
    }
}

void Graphic::drawCircle(){
    for(int i = 0; i < 360; i++){
        const Vector2 newPxPos{
            int(std::roundf(std::cos((float)i * (M_PIf / 180.0f)) *  ((width-1)/2.0f)) + (width-1)/2.0f),
            int(std::roundf(std::sin((float)i * (M_PIf / 180.0f)) * ((height-1)/2.0f)) + (height-1)/2.0f)
        };
        data[newPxPos.x][newPxPos.y] = 'O';
    }
}