#include "triangle.h"

bool is_triangle(triangle_t t) {
  return t.a + t.b > t.c && t.a + t.c > t.b && t.b + t.c > t.a;
}

bool is_isosceles(triangle_t t) {
  return is_triangle(t) && (t.a == t.b || t.a == t.c || t.b == t.c);
}

bool is_equilateral(triangle_t t) {
  bool result = t.a == t.b && t.a == t.c;
  if (t.a == 0) return false;
  return result;
}

bool is_scalene(triangle_t t) {
  return is_triangle(t) && !is_isosceles(t) && !is_equilateral(t);
}