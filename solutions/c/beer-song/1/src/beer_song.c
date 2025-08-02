#include "beer_song.h"
#include <string.h>
#include <stdio.h>
#define BUFFER_SIZE (128)

void verse(char *response, int bottles) {
  char *verse_n = "%d bottles of beer on the wall, %d bottles of beer.\n"
    "Take one down and pass it around, %d bottles of beer on the wall.\n";
  char *verse_2 = "2 bottles of beer on the wall, 2 bottles of beer.\n"
    "Take one down and pass it around, 1 bottle of beer on the wall.\n";
  char *verse_1 = "1 bottle of beer on the wall, 1 bottle of beer.\n"
    "Take it down and pass it around, no more bottles of beer on the wall.\n";
  char *verse_0 = "No more bottles of beer on the wall, no more bottles of beer.\n"
       "Go to the store and buy some more, 99 bottles of beer on the wall.\n";

  switch (bottles) {
  case 2:
    strcpy(response, verse_2);
    break;
  case 1:
    strcpy(response, verse_1);
    break;
  case 0:
    strcpy(response, verse_0);
    break;
  default:
    sprintf(response, verse_n, bottles, bottles, bottles - 1);
    break;
  }
}

void sing(char *response, int start, int end) {
  memset(response, '\0', strlen(response));
  char tmp[BUFFER_SIZE];
  while (start >= end) {
    
    verse(tmp, start);
    strcat(response, tmp);
    
    if (start > end) strcat(response, "\n");
    
    start--;
  }
}