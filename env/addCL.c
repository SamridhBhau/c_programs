#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
  long total = 0;
  char *badchar;
  for (int i = 1; i < argc; i++){
    total += strtol(argv[i], &badchar, 10);
  }
  
  if (*badchar == '\0'){
    printf("%ld\n", total);
  }
  else {
    printf("Invalid input\n");
  }

  return 0;
}
