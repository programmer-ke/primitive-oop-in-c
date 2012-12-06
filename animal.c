#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "animal.h"


void Animal_move(void *self, int steps)
{
  printf("Moves %d steps\n", steps);
}


void Animal_sound(void *self)
{
  printf("Makes a sound\n");
}

void Animal_destroy(void *self)
{
  Animal *this = self;
  if (this) {
    if (this->description) free(this->description);
    free(this);
  }
}

int Animal_init(void *self, const char *description)
{
  Animal *this = self; 
  this->description = strdup(description);
  return 1;
}

void *Animal_new(Animal proto, size_t size, const char *description) 
{
  if (!proto.move) proto.move = Animal_move;
  if (!proto.make_sound) proto.make_sound = Animal_sound;
  if (!proto.destroy) proto.destroy = Animal_destroy;
  if (!proto.init) proto.init = Animal_init;

  Animal *animal = calloc(1, size);
  *animal = proto;

  int initval = animal->init(animal, description);
  if (initval)
    return animal;
  else 
    return NULL;
}
