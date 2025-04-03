//If you manually allocated it, you have to manually free it when you’re done with it.
#include <stdio.h>
#include <stdlib.h>

int main() {
  // malloc - accepts number of bytes to allocate, returns void pointer to that block 
  int *p = malloc(sizeof(int));
  if (p == NULL)
    printf("Error allocating 1 ints\n");
  else {
    *p = 12; 

    printf("%d\n", *p);

    free(p);
  }

  int *x;

  if ((x = malloc(sizeof(int) * 10)) == NULL)
    printf("Error allocating 10 ints\n");
  else {
    for (int i = 0; i < 10; i++){
      x[i] = i * 5;
    }
    for (int i = 0; i < 10; i++){
      printf("%d\n", x[i]);
    }

    free(x);
  }

  // malloc doesn't zero the memory by default, we can use memset
  // calloc clears the memory to zero
  //Allocate space for 10 ints with malloc(), initialized to 0:
  int *q = calloc(10, sizeof(int));


  return 0;
}
