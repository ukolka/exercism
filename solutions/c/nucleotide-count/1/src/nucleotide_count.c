#include "nucleotide_count.h"
#include <stdlib.h>
#include <stdio.h>
#define COUNT_STR_LEN 64

typedef struct {
  int A;
  int C;
  int G;
  int T;
} NucCount;

void init_nc(NucCount *nc) {
  nc->A = 0;
  nc->C = 0;
  nc->G = 0;
  nc->T = 0;
}

char *count_to_string(const NucCount *nc) {
  char *result = calloc(COUNT_STR_LEN, sizeof(char));
  
  sprintf(
          result,
          "A:%d C:%d G:%d T:%d",
          nc->A,
          nc->C,
          nc->G,
          nc->T);

  return result;
}

char *invalid_count() {
  return (char *) calloc(1, sizeof(char));
}

char *count(const char *dna_strand) {
  if (dna_strand == NULL) return NULL;

  NucCount nc;
  init_nc(&nc);

  char ch;
  while ((ch = *dna_strand++))
    switch (ch) {
    case 'A':
      nc.A++;
      break;
    case 'C':
      nc.C++;
      break;
    case 'G':
      nc.G++;
      break;
    case 'T':
      nc.T++;
      break;
    default:
      return invalid_count();
      break;
    }

  return count_to_string(&nc);
}