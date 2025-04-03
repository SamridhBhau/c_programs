#include <stdio.h>

int j = 13; // File scope visible everywhere in file after this

int main() {
  int a = 12; // local to outer block, visible to inner block
  int i = 10;

  if (a == 12) {
    int b = 99; // local to inner block, not visible in outer block

    printf("%d %d\n", a, b); // OK
  }

  {
    int i = 20;
    printf("%d\n", i);  // Inner scope i, 20 (outer i is hidden)
  }

  printf("%d\n", a); // in a's scope

  //printf("%d\n", b);  -- out of b's scope

  printf("%d\n", i); // outer scope i, 10

  return 0;
}
