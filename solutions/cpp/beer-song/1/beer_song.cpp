#include "beer_song.h"

namespace beer_song {
    std::string verse(int n) {
        if (n == 0)
            return "No more bottles of beer on the wall, no more bottles of beer.\n"
                "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
        if (n == 1)
            return "1 bottle of beer on the wall, 1 bottle of beer.\n"
                "Take it down and pass it around, no more bottles of beer on the wall.\n";

        std::string nstr(std::to_string(n));
        std::string nstr2(std::to_string(n - 1));
        std::string bottleStr = n % 10 == 1 ? " bottle" : " bottles";
        std::string bottleStr2 = (n - 1) % 10 == 1 ? " bottle" : " bottles";
        std::string result = nstr + bottleStr + " of beer on the wall, ";
        result += nstr + bottleStr + " of beer.\n";
        result += "Take one down and pass it around, ";
        result += nstr2 + bottleStr2 + " of beer on the wall.\n";
        return result;
    }
    std::string sing(int start, int end) {
        std::string result = "";
        for (int i = start; i >= end; i--) {
            result += verse(i);
            if (i != end)
                result += "\n";
        }
        return result;
    }
}  // namespace beer_song
