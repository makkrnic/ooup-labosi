#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char const* (*PTRFUN)();

typedef struct {
  PTRFUN* vtable;
  char *name;
} Parrot;

char const *greet() {
  return "Sto mu gromova!";
}

char const *menu() {
  return "crackers";
}

char const *name(Parrot *p) {
  return p->name;
}

PTRFUN funTable[3] = {name, greet, menu};

void *create (char const* name) {
  Parrot *p = (Parrot *)malloc (sizeof (Parrot));
  p->name = (char *)name;
  p->vtable =(PTRFUN*) malloc (3*sizeof(PTRFUN*));
  memcpy (p->vtable, funTable, 3*sizeof(PTRFUN*));

  return p;
}
