#include "clock.h"

namespace date_independent
{
    clock::clock(int hour, int minute)
    {
        int a_day = 24 * 60;
        minutes = a_day + (hour * 60 + minute) % a_day;
    }

    void clock::add(int minutes_)
    {
        minutes += minutes_;
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
} // namespace date_independent
