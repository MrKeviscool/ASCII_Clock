#pragma once
#include <chrono>
#include <Time.hpp>

class Clock{
public:
    Clock();

    Time time;

    const Time& getTime();
    void updateTime();
    void setTimeZone(const float UTCOffset);

private:
    float timeZone = 10.5;
};