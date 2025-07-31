#ifndef SPACEAGE_H
#define SPACEAGE_H

#define BASELINE_SEC 31557600
#define EARTH 1
#define MERCURY 0.2408467
#define VENUS 0.61519726
#define MARS 1.8808158
#define JUPITER 11.862615
#define SATURN 29.447498
#define URANUS 84.016846
#define NEPTUNE 164.79132


float convert_planet_age(float orbital_period, long age_seconds);

#endif