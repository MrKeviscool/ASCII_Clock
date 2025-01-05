#include <iostream>
#include <chrono>
#include <cmath>
#include <cstring>
#include <thread>

#include "Clock.hpp"
#include "Graphic.hpp"

const float map(const float val, const float inMin, const float inMax, const float outMin, const float outMax){
    return (val - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

int main(int argc, char** argv){
    Clock clock;
    Graphic graphic;

    if(argc == 3)
        graphic.setScreenSize(std::stoi(argv[1]), std::stoi(argv[2]));
    else graphic.setScreenSize(40, 20);


    for(;;){
        graphic.drawTime(clock.getTime());
        graphic.draw();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

}