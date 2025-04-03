#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  char *p = aligned_alloc(64 , 256);

  strcpy(p, "Hello, world!");
  printf("%s\n", p);

  free(p);

  return 0;
}
