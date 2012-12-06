#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "animal.h"


void Animal_move(void *self, int steps)
{
  assert(self != NULL);
  printf("Moves %d steps\n", steps);
}


void Animal_sound(void *self)
{
  assert(self != NULL);
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
  assert(self!=NULL);
  Animal *this = self; 
  this->description = strdup(description);
  if (this->description == NULL)
    return 0;
  else
    return 1;
}

void *Animal_new(Animal proto, size_t size, const char *description) 
{
  assert(size);
  if (!proto.move) proto.move = Animal_move;
  if (!proto.make_sound) proto.make_sound = Animal_sound;
  if (!proto.destroy) proto.destroy = Animal_destroy;
  if (!proto.init) proto.init = Animal_init;

  Animal *animal = calloc(1, size);
  assert(animal != NULL);
  *animal = proto;

  int initval = animal->init(animal, description);
  if (initval)
    return animal;
  else {
    animal->destroy(animal);
    return NULL;
  }
}
