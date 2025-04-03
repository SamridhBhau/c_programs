#include <stdio.h>

// all fields overlap in the same stretch of memory
union foo {
  int a, b, c, d, e, f;
  float g, h;
  char i, j, k, l;
};

union A {
  int i;
  float f;
  char *s;
};

union foo2 {
  float b;
  short a;
};

int main() {
  printf("%zu\n", sizeof(union foo)); // 4

  union A a;
  a.i = 14;
  printf("%d\n", a.i);

  a.f = 14.032;
  printf("%f\n", a.f);

  a.s = "Hello, World";
  printf("%s\n", a.s);

  a.s = "Unions";
  printf("%s\n", a.s);

  int *int_ptr = (int *)&a;
  float *float_ptr = (float *)&a;
  char **str_ptr = (char **)&a; 

  a.i = 25;
  printf("%d\n", *int_ptr);

  a.f = 12.223;
  printf("%f\n", *float_ptr);

  a.s = "Pointers";
  printf("%p\n", &a);
  printf("%p\n", str_ptr);
  printf("%s\n", *str_ptr);

  union A *p = (union A*) int_ptr;
  p->i = 14;
  printf("%d\n", p->i);

  union A b;
  printf("%zu\n", sizeof(union A));

  return 0;
}
