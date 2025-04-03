#include <stdio.h>

#define N 50

int main() {
  char buffer[N];

  setvbuf(stdout, buffer, _IOFBF, N);

  return 0;
}
