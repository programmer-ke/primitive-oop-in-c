#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "myanimals.h"
#include "dbg.h"

void Human_move(void *self, int steps)
{
  check(self != NULL, "self is NULL");
  printf("walkes %d strides\n", steps);
 error:
  ;
}

void Human_sound(void *self)
{
  check(self != NULL, "self is NULL");
  printf("Talks\n");
 error:
  ;
}

int Human_init(void *self, const char *species)
{
  Human *h = NULL;
  check(self != NULL, "self is NULL");
  h = self;
  h->species = strdup(species);
  check_mem(h->species);
  return 1;
 error:
  if (h->species) free(h->species);
  return 0;
}

void Human_destroy(void *self)
{
  Human *this = self;
  if (this) {
    if (this->species) free(this->species);
    Animal_destroy(this);
  }
}

Animal HumanProto = {
  .init = Human_init,
  .make_sound = Human_sound,
  .move = Human_move,
  .destroy = Human_destroy
};

void Duck_move(void *self, int steps)
{
  check(self != NULL, "self is NULL.");
  printf("wobbles %d steps\n", steps);
 error:
  ;
}

void Duck_sound(void *self)
{
  check(self != NULL, "self is NULL.");
  printf("Quacks");
 error:
  ;
}

int Duck_init(void *self, const char *species)
{
  Duck *d = NULL;
  check(self != NULL, "self is NULL");
  d = self;
  d->species = strdup(species);
  check_mem(d->species);
  return 1;
 error:
  if (d->species) free(d->species);
  return 0;
}

void Duck_destroy(void *self)
{
  Duck *this = self;
  if (this) {
    if (this->species) free(this->species);
    Animal_destroy(this);
  }
}


Animal DuckProto = {
  .move = Duck_move,
  .make_sound = Duck_sound,
  .init = Duck_init,
  .destroy = Duck_destroy
};

int main()
{
  Animal AnimalProto = {};
  Animal *animal = NEW(Animal, "An animal"); 
  Human *human = NEW(Human, "Homo sapien"); 
  Duck *duck = NEW(Duck, "Anas rubripes"); 
  printf("%s ", animal->description);
  animal->move(animal, 5);
  animal->make_sound(animal);
  printf("%s ", human->species);
  human->proto.move(human, 5);
  human->proto.make_sound(human);
  printf("%s ", duck->species);
  duck->proto.move(duck, 5);
  duck->proto.make_sound(duck);
  printf("\n");
  animal->destroy(animal);
  duck->proto.destroy(duck);
  human->proto.destroy(human);
  return 0;
}
