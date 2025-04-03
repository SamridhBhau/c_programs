#include <stdio.h>
#include <stddef.h>


struct foo {
  int a;
  char b;
  int c;
  char d;
};

int main(void) {
  printf("%zu\n", sizeof(int) + sizeof(char) + sizeof(int) + sizeof(char));
  printf("%zu\n", sizeof(struct foo)); // compiler adds paddings 
  
  printf("%zu\n", offsetof(struct foo, a));
  printf("%zu\n", offsetof(struct foo, b));
  printf("%zu\n", offsetof(struct foo, c));
  printf("%zu\n", offsetof(struct foo, d));
  
  
  return 0;
}
