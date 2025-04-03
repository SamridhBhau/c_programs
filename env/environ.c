#include <stdio.h>

extern char **environ;

int main() {
  
  for (char **p = environ; *p != NULL; p++){
    printf("%s\n", *p);
  }
  
  return 0;
}
