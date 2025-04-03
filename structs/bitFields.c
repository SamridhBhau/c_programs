#include <stdio.h>

struct foo {
  unsigned a:5; // 5 bits
  unsigned b:5;
  unsigned c:3; // 3 bits
  unsigned d:3;
};

struct foo2 {
  unsigned a; // 4 bytes
  unsigned b;
  unsigned c;
  unsigned d;
};

struct bar {
  unsigned char a:2;
  unsigned char :5; // unnamed bit-field
  unsigned char b:1;
};

struct bit {
  unsigned char a:3;  // a and b fit into one charA
  unsigned char b:3;

  unsigned char c:3;  // c and d go into second char leaving a gap of 2 bits between b and c
  unsigned char d:3;

  unsigned char e:3;  // e needs a third char
};

// It puts a and b into one int, with a 3-bit gap between them. Then : 0 advances to the next int, 
// so c and d fit into that one. 
struct bit2 {
  unsigned int a:3;
  unsigned int :3;
  unsigned int b:5;

  unsigned int :0;

  unsigned int c:5;
  unsigned int :3;
  unsigned int d:5;
};

int main() {

  printf("%zu\n", sizeof(struct foo));  // 4
  printf("%zu\n", sizeof(struct foo2)); // 16
  printf("%zu\n", sizeof(struct bit));  // 3

  return 0;
}
