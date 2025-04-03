#include <stdio.h>
#include <stdlib.h>

int main() {
  char s[13];
  float f = 3.14159;

  snprintf(s, 13, "Pi: %f", f);

  printf("%s\n", s);

  char *pi = "3.14159";
  float f2;
  f = atof(pi);
  
  printf("%f\n", f);

  char *str = "3490";
  unsigned long x = strtoul(str, NULL, 10); // strtoul doesn't give undefined behaviour. It just retuns 0
  printf("%lu\n", x);

  char *str2 = "101010";
  unsigned long int num  = strtoul(str2, NULL, 2); // base 2

  printf("%lu\n", num); // 42
  
  char *str3 = "34x90";
  char *badchar;

  unsigned long int num2 = strtoul(str3, &badchar, 10);

  printf("%lu\n", num2); // 34
  //

  printf("Invalid character: %c\n", *badchar); // x

  char *str4 = "3490";
  unsigned long int num3 = strtoul(str4, &badchar, 10);

  if (*badchar == '\0')
    printf("Success! %lu\n", num3);
  else {
    printf("Partial conversion: %lu\n", num3);
    printf("Invalid character: %c\n", *badchar);
  }

  char c = '6';

  int d = c; // d has value 54, the code point for '6'

  int y = c - '0'; // y has value 6

  printf("%d\n", y);

  return 0;
}
