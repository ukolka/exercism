#if !defined(BEER_SONG_H)
#define BEER_SONG_H
#include <string>

namespace beer_song {
    std::string verse(int n);
    std::string sing(int start, int end = 0);
}  // namespace beer_song

#endif // BEER_SONG_H