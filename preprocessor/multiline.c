#include <stdio.h>

#define PRINT_NUMS_TO_PRODUCT(a, b) do{ \
  int product = (a) * (b);  \
  for (int i = 0; i < product; i++) \
    printf("%d\n", i);  \
  } while(0)  \

int main() {
  PRINT_NUMS_TO_PRODUCT(1, 5);
  PRINT_NUMS_TO_PRODUCT(1, 15);


  return 0;
}
