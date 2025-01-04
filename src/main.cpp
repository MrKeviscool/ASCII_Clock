#include <iostream>
#include <chrono>
#include <cmath>
#include <cstring>

#include "Clock.hpp"
#include "Graphic.hpp"

int main(){
    Clock clock;

    const Time time = clock.getTime();
    std::cout << time.year << '\n';
    std::cout << time.hour << ':';
    std::cout << time.minute << ':';
    std::cout << time.second << '\n';
    Graphic graphic;
    graphic.draw();
}