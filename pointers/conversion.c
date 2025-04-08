#include <stdio.h>
#include <string.h>

int main() {
  char name[] = "sam";
  char **ptr;

  ptr = (char **)name;

  for (int i = 0; i < strlen(name); i++){
    printf("%c", (*ptr)[i]);
  }

  return 0;
}
