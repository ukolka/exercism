#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna) {
  if (dna == NULL)
    return NULL;

  char *rna = calloc(strlen(dna), sizeof(char));
  char *rna_cur = rna;

  char dna_ch;
  while ((dna_ch = *dna++))
    switch (dna_ch) {
    case 'G':
      *rna_cur++ = 'C';
      break;
    case 'C':
      *rna_cur++ = 'G';
      break;
    case 'T':
      *rna_cur++ = 'A';
      break;
    case 'A':
      *rna_cur++ = 'U';
      break;
    default:
      return NULL;
    }

  return rna;
}