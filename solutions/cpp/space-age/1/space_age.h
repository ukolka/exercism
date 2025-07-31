#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

namespace space_age {
    class space_age {
        private:
            long int secs{};
            float earth_years{};
        public:
            space_age(long int secs) : secs(secs) {
                earth_years = (float) secs / 31557600.0;
            }

            int seconds() const {
                return secs;
            }

            float on_mercury() const {
                return earth_years / 0.2408467;
            }

            float on_venus() const {
                return earth_years / 0.61519726;
            }

            float on_earth() const {
                return earth_years;
            }

            float on_mars() const {
                return earth_years / 1.8808158;
            }

            float on_jupiter() const {
                return earth_years / 11.862615;
            }

            float on_saturn() const {
                return earth_years / 29.447498;
            }

            float on_uranus() const {
                return earth_years / 84.016846;
            }

            float on_neptune() const {
                return earth_years / 164.79132;
            }
    };
}  // namespace space_age

#endif // SPACE_AGE_H