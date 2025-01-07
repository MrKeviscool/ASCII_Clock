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

const char helpMsg[] = 
"Usage:\n\
    clock [OPTION]...\n\
    clock [OPTION]... [X RESOLUTION] [Y RESOLUTION]\n\
\n\
print a analog clock based on system time to terminal\n\
\n\
Options:\n\
 -h, --help      this help message\n\
 -o, --offset[N] set GTC timezone offset to N (float)\n";

const char argError[] = "argument error, type \'-h\' or \'--help\' for help\n\n";

int main(int argc, char** argv){
    Clock clock;
    Graphic graphic;

    const int defaultSizeX = 40, defaultSizeY = 20;

    try{
        if(argc == 2){
            if(!std::strcmp(argv[1], "-h") || !std::strcmp(argv[1], "--help"))
                std::cout << helpMsg;
            else throw std::invalid_argument("invalid arguments");
        }
        else if(argc > 2){
            if(argc == 3 && !std::strcmp(argv[1], "-o") || !std::strcmp(argv[1], "--offset")){
                clock.setTimeZone(std::stof(argv[2]));
                graphic.setScreenSize(defaultSizeX, defaultSizeY); //default
            }
            else if(argc == 3){
                graphic.setScreenSize(std::stoi(argv[1]), std::stoi(argv[2]));
            }
            else if(argc == 5 && !std::strcmp(argv[3], "-o") || !std::strcmp(argv[3], "--offset")){
                graphic.setScreenSize(std::stoi(argv[1]), std::stoi(argv[2]));
                clock.setTimeZone(std::stof(argv[4]));
            }
            else if(argc == 5){
                graphic.setScreenSize(std::stoi(argv[3]), std::stoi(argv[4]));
                clock.setTimeZone(std::stof(argv[2]));
            }
            else{
                throw(std::invalid_argument("invalid arguments"));
            }
        }
        else{
            graphic.setScreenSize(defaultSizeX, defaultSizeY); //default
        }
    }
    catch(std::invalid_argument badArg){
        std::cout << argError;
        throw;
    }

    for(;;){
        graphic.drawTime(clock.getTime());
        graphic.draw();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

}