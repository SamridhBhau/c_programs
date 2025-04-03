#include <stdio.h>

void increment(int *p){
  *p += 1;
}

int main() {
  int x = 14;
  int *p = &x;

  int *pt, z; // pt is a pointer to int whereas z is just an int
  printf("Address of x: %p\n", (void *)&x);
  printf("%d\n", *p);
  
  increment(&x);
  printf("Value after calling increment function: %d\n", x);

  int *p2 = NULL; // doesn't point to anything

  printf("%zu\n", sizeof p); // prints size of 'int*'  
  printf("%zu\n", sizeof *p); // prints size of 'int'  
 
  return 0;
}
