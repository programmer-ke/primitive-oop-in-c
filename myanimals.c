#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myanimals.h"

void Human_move(void *self, int steps)
{
  printf("walkes %d strides\n", steps);
}

void Human_sound(void *self)
{
  printf("Talks\n");
}

int Human_init(void *self, const char *species)
{
  Human *h = self;
  h->species = strdup(species);
  return 1;
}

Animal HumanProto = {
  .init = Human_init,
  .make_sound = Human_sound,
  .move = Human_move };

void Duck_move(void *self, int steps)
{
  printf("wobbles %d steps\n", steps);
}

void Duck_sound(void *self)
{
  printf("Quacks");
}

int Duck_init(void *self, const char *species)
{
  Duck *d = self;
  d->species = strdup(species);
  return 1;
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
  return 0;
}
