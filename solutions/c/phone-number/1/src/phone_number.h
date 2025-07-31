#ifndef PHONE_NUMER_H
#define PHONE_NUMER_H
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#define PHONE_NUM_LEN (10)
#define AREA_CODE_LEN (3)
#define FORMATTED_PHONE_NUM_LEN (14)

char *phone_number_clean(const char *);
char *phone_number_get_area_code(const char *);
char *phone_number_format(const char *);

#endif