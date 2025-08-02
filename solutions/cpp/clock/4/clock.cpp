#include "clock.h"

namespace date_independent
{
    clock::clock(int hour, int minute)
    {
        minutes = hour * 60;
        add(minute);
    }

    void clock::add(int minutes_)
    {
        int a_day = 24 * 60;
        minutes += minutes_;
        // bring it under a day
        minutes %= a_day;
        // take care of the negative
        minutes += a_day;
        // bring it under a day again
        minutes %= a_day;
    }

    string clock::toString() const
    {
        int hour = minutes / 60 % 24;
        int minute = minutes % 60;

        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << hour << ":"
            << std::setw(2) << std::setfill('0') << minute;

        return oss.str();
    }

    clock clock::plus(int minutes_) const {
        return {0, minutes + minutes_};
    }

    bool clock::operator==(const clock& other) const {
        return minutes == other.minutes;
    }    

    bool clock::operator!=(const clock& other) const {
        return !(*this == other);
    }
} // namespace date_independent
