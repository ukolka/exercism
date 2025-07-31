#if !defined(CLOCK_H)
#define CLOCK_H
#include <string>
#include <iomanip>
using namespace std;

namespace date_independent {
    class clock {
    public:
        clock(int hour, int minute); 

        static clock at(int hour, int minute) {
            return clock(hour, minute);
        }

        void add(int minutes_); 
        clock plus(int minutes_) const; 

        string toString() const; 

        operator string() const {
            return toString();
        } 

        bool operator==(const clock& other) const; 
        bool operator!=(const clock& other) const; 

    private:
        int minutes;
    };
    }

#endif