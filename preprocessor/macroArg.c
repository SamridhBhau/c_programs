#include <math.h>
#include <stdio.h>
#include <limits.h>

#define SQR(x) ((x) * (x))
#define TRIANGLE_AREA(w, h) (0.5 * (w) * (h))
#define QUADP(a, b, c) ((-(b) + sqrt((b)*(b) - 4 * (a) * (c))) / (2 * (a)))
#define QUADM(a, b, c) ((-(b) - sqrt((b)*(b) - 4 * (a) * (c))) / (2 *(a)))
#define QUAD(a, b, c) QUADP(a, b, c), QUADM(a, b, c)

#define X(a, b, ...) (10*(a) + 20*(b)), __VA_ARGS__
#define A(...) #__VA_ARGS__   //stringified
#define STR(x) #x
#define PRINT_INT_VAL(x) printf("%s = %d\n", #x, x)
#define CAT(a, b) a ## b

int main() {
  printf("%d\n", SQR(3+4));
  printf("%f\n", TRIANGLE_AREA(1+2, 3+2));

  printf("x = %f or x = %f\n", QUAD(2, 10, 5));

  printf("%d %f %s %d\n", X(5, 4, 3.14, "Hi", 12));
  printf("%s\n", A(3.14, "Hi", 5));

  printf("%s\n", STR(3.14159));

  int a = 54;
  PRINT_INT_VAL(a);

  printf("%f\n", CAT(3.14, 1592));

  return 0;
}
