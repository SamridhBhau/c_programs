#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct len_string {
  int length;
  char data[8];
};

struct len_string2 {
  int length;
  char data[];
};

struct len_string2 *len_string_from_c_string(char *s){
  int len = strlen(s);
  struct len_string2 *ls = malloc(sizeof *ls + len);
  ls->length = len;

  memcpy(ls->data, s, len);

  return ls;
}

int main() {
  struct len_string *s = malloc(sizeof *s + 40);

  strcpy(s->data, "Hello World"); // doesn't crash but accessible beyond end of array is undefined behaviour

  struct len_string2 *s2 = len_string_from_c_string("Hello, World");  // len_string2 is legal way to do the same

  for(int i = 0; i < s2->length; i++){
    printf("%c", s2->data[i]);
  }
  printf("\n");

  return 0;
}
