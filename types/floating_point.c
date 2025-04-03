#include <stdio.h>
#include <float.h>

int main() {
  printf("%d\n", FLT_RADIX);
  printf("%d\n", FLT_DIG);
  printf("%d\n", DBL_DIG);

  float f = 3.14159f;
  float g = 0.00000265358f;

  printf("%.5f\n", f);
  printf("%.11f\n", g);

  f += g;
  printf("%.11f\n", f); // wrong output
  //
  long double x = 3.14L;
  float x2 = 3.14f; 

  printf("%e\n", 123456.0);

  return 0;
}
