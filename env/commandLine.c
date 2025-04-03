#include <stdio.h>
// argc - argument count, including the program name itself
int main(int argc, char **argv) {
  for (int i = 0; i < argc; i++){
    printf("arg %d: %s\n", i, *(argv+i));
  }

  return 0;
}
