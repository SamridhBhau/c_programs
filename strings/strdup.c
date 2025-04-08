#include <stdio.h>
#include <string.h>


int main() {
  char *s = "Hello World";
  char *dup = strdup(s+6);

  printf("%s\n", dup);

  return 0;
}
