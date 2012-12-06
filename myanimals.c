#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "myanimals.h"

void Human_move(void *self, int steps)
{
  assert(self != NULL);
  printf("walkes %d strides\n", steps);
}

void Human_sound(void *self)
{
  assert(self != NULL);
  printf("Talks\n");
}

int Human_init(void *self, const char *species)
{
  assert(self != NULL);
  Human *h = self;
  h->species = strdup(species);
  if (h->species == NULL)
    return 0;
  else
    return 1;
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
  .move = Human_move };

void Duck_move(void *self, int steps)
{
  assert(self != NULL);
  printf("wobbles %d steps\n", steps);
}

void Duck_sound(void *self)
{
  assert(self != NULL);
  printf("Quacks");
}

int Duck_init(void *self, const char *species)
{
  assert(self != NULL);
  Duck *d = self;
  d->species = strdup(species);
  if (d->species == NULL)
    return 0;
  else 
    return 1;
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
  .init = Duck_init };

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
