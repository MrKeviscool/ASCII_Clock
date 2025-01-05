#include "Graphic.hpp"

#include <cstring>
#include <iostream>
#include <cmath>
#include "Time.hpp"

extern const float map(const float val, const float inMin, const float inMax, const float outMin, const float outMax);

const int
    HOUR_HAND_LEN   = 50,    
    MINUTE_HAND_LEN = 80,  
    SECOND_HAND_LEN = 100;

Graphic::Graphic(){

};

Graphic::Graphic(int width, int height) : width(width), height(height){
    setScreenSize(width, height);
}

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
    std::system("clear");
    drawCircle();
}

void Graphic::destroyData(){
    if(!data)return;
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
        const Vector2i newPxPos{
            int(std::roundf(std::cos((float)i * (M_PIf / 180.0f)) * ((width - 1) / 2.0f)) + (width - 1) / 2.0f),
            int(std::roundf(std::sin((float)i * (M_PIf / 180.0f)) * ((height - 1) / 2.0f)) + (height - 1) / 2.0f)};
        data[newPxPos.x][newPxPos.y] = 'O';
    }
}

Vector2i Graphic::getSize(){
    return {width, height};
}

void Graphic::drawHand(int lengthPercent, int angle, char character)
{

    const Vector2i origin{
        width/2,
        height/2
    };

    const Vector2i targetPos{
        static_cast<int>(std::roundf(std::cos(((float)angle - 90) * (M_PIf / 180.0f)) * origin.x * (lengthPercent / 100.0f))),
        static_cast<int>(std::roundf(std::sin(((float)angle - 90) * (M_PIf / 180.0f)) * origin.y * (lengthPercent / 100.0f))),
    };

    float slope;
    if(targetPos.x == 0) slope = ((targetPos.y >= 0)? -origin.y-1 : origin.y-1); //target pos = how much you add to origin
    else
        slope = (targetPos.y) / (float)(targetPos.x-1);

    float verticalAccumulator = 0;

    int x = 0;
    do{
        const Vector2i placePos{
            origin.x + (targetPos.x > 0? x : -x),
            origin.y + (int)(targetPos.x > 0? std::roundf(verticalAccumulator) : -std::roundf(verticalAccumulator))
        };
        verticalAccumulator += slope;
        data[placePos.x][placePos.y] = character;
        if(x != 0 || targetPos.x < 2){
            int roundedSlope = (int)std::roundf(slope);
            int roundedAccum = (int)std::roundf(verticalAccumulator);
            for(int y = 1; y < std::abs(roundedSlope)+1; y++){
                data[placePos.x][placePos.y + ((roundedAccum > 0)? -y : y)] = character; //error because you should not be minusing nums at start
            }
        }
        x++;
    } while(x < std::abs(targetPos.x));
}

void Graphic::drawTime(const Time& time){
    clearGraphics();
    drawHand(100, (int)map(time.second, 0, 60, 0, 360), 'S');
    drawHand(100, (int)map(time.minute, 0, 60, 0, 360), 'M');
    drawHand(100, (int)map(time.hour  , 0, 12, 0, 360), 'H');
}