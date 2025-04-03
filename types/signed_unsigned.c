#include <stdio.h>
#include <limits.h>

int main() {
  printf("%zu\n", sizeof(int));
  printf("%zu\n", sizeof(float));
  unsigned a;

  char c = 'B';
  printf("%d\n", c); // 66
  //
  if (CHAR_MAX == UCHAR_MAX)
    printf("char == unsigned\n");
  else
    printf("char == signed\n");

  return 0;
}
