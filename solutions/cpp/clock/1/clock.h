#if !defined(CLOCK_H)
#define CLOCK_H
#include <string>
#include <iomanip>
using namespace std;

namespace date_independent {
    class clock {
    public:
        clock(int hour, int minute); 

        static string at(int hour, int minute) {
            return clock(hour, minute).toString();
        }

        void add(int minutes_); 

        string toString() const; 

    private:
        int minutes;
    };
    }

#endif