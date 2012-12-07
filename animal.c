#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "animal.h"
#include "dbg.h"


void Animal_move(void *self, int steps)
{
  check(self != NULL, "self is null.");
  printf("Moves %d steps\n", steps);
 error:
  ;
}


void Animal_sound(void *self)
{
  check(self != NULL, "self is null.");
  printf("Makes a sound\n");
 error:
  ;
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
  check(self != NULL, "self is null.");
  Animal *this = self; 
  this->description = strdup(description);
  check_mem(this->description);
  return 1;
 error:
  if (this->description) free(this->description);
  return 0;
}
 
void *Animal_new(Animal proto, size_t size, const char *description) 
{
  int initval = 0;
  Animal *animal = NULL;
  check(size, "Cannot create an object of size 0.");
  if (!proto.move) proto.move = Animal_move;
  if (!proto.make_sound) proto.make_sound = Animal_sound;
  if (!proto.destroy) proto.destroy = Animal_destroy;
  if (!proto.init) proto.init = Animal_init;

  animal = calloc(1, size);
  check_mem(animal);
  *animal = proto;

  initval = animal->init(animal, description);
  check(initval, "Could not initiate %s", description);
  return animal;
 error:
  if (animal) {
    if (animal->description) free(animal->description);
    animal->destroy(animal);
  }
  return NULL;
}
