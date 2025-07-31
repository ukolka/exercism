#include "allergies.h"
#include <stdlib.h>
#define allergen_mask(a) (1 << (a))

bool is_allergic_to(allergen_t allergen, int score) {
  score = score % allergen_mask(ALLERGEN_COUNT);
  int allergen_m = allergen_mask(allergen);

  return allergen_m & score;
}

void get_allergens(int score, allergen_list_t *list) {
  list->allergens = malloc(ALLERGEN_COUNT * sizeof(allergen_t));
  allergen_t *ap = list->allergens;
  list->count = 0;
  
  for (int a = ALLERGEN_EGGS; a < ALLERGEN_COUNT; a++) {
    if (is_allergic_to(a, score)) {
      *ap++ = a;
      list->count++;
    }
  }
}