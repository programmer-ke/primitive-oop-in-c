#ifndef _myanimals_h
#define _myanimals_h

#include "animal.h"

typedef struct {
  Animal proto;
  char* species;
} Human;

void Human_move(void *self, int steps);
void Human_sound(void *self);
int Human_init(void *self, const char *species);

typedef struct { 
  Animal proto;
  char *species;
} Duck;

void Duck_move(void *self, int steps);
void Duck_sound(void *self);
int Duck_init(void *self, const char *species);

#endif
