#ifndef _animal_h
#define _animal_h

typedef struct {
  char *description;
  void (*move)(void *self, int steps);
  void (*make_sound)(void *self);
  void (*destroy)(void *self);
  int (*init)(void *self, const char *description);
} Animal;

void Animal_move(void *self, int steps);
void Animal_sound(void *self);
void Animal_destroy(void *self);
int Animal_init(void *self, const char *description);

void *Animal_new(Animal proto, size_t size, const char *description);

#define NEW(N, d) Animal_new(N##Proto, sizeof(N), d)

#endif

