#include "Clock.hpp"

#include <cmath>

Clock::Clock() = default;

const Time& Clock::getTime() {
    updateTime();
    return time;
}

void Clock::updateTime(){
    const std::chrono::seconds timeSinceEpoch{std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()) + std::chrono::seconds(static_cast<int64_t>(timeZone*3600))};
    time.year   = (timeSinceEpoch.count() / (60.0 * 60.0 * 24.0 * 365.2425)) + 1970;
    time.hour   = std::fmod(timeSinceEpoch.count() / (60 * 60.0f), 12.0f); 
    time.minute = std::fmod((timeSinceEpoch.count() / 60.0), 60.0);
    time.second = timeSinceEpoch.count()  % 60;
}

void Clock::setTimeZone(const float UTCOffset){
    timeZone = UTCOffset;
}