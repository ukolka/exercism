#ifndef ETL_H
#define ETL_H

typedef struct {
  int value;
  char *keys;
} legacy_map;

typedef struct {
  char key;
  int value;
} new_map;

int convert(legacy_map *, int, new_map**);

#endif