#include <stdio.h>
#include <stdlib.h>

int main() {
  char *val = getenv("FROTZ");

  if (val == NULL){ 
    printf("Cannot find the FROTZ environment variable\n");
    return EXIT_FAILURE;
  }

  printf("Value: %s\n", val);


  return 0;
}
