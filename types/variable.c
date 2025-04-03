#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
  int i = 15;
  float j = 2.5;
  char *s = "var";

  printf("string = %s, integer = %d, float = %f\n", s,i,j);
  
  int b = 23;
  if (b)
    printf("Success!\n");

  bool t = true;
  if (t)
    printf("Success!\n");

  int x = 10;
  int y = 5 + x++;
  printf("%d, %d\n", x, y);
  
  int z = (1,2,3);
  printf("%d\n", z); // because command operator returns rightmost value
 
  if (!(x < 9))  // ! has higher precedence than other boolean operators hence the ()
    printf("Success\n");

  printf("%zu\n", sizeof x);
  printf("%zu\n", sizeof j);

  return 0;
}
