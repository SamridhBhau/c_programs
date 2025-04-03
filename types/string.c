#include <stdio.h>
#include <string.h>

int main(){
  int i;
  char *str = "Hello";

  printf("%s\n", str);

  for (i = 0; i < 5; ++i)
    printf("%c", str[i]);
  printf("\n");

  // str[0] = 'z'; // seg fault

  char str2[] = "Hello"; // Null character implicitly included
  str2[0] = 'z';  // works
  printf("%s\n", str2);
  printf("%zu\n", strlen(str2));

  int count = 0;
  while (str2[count] != '\0')
    count++;
  printf("%d\n", count);

  char *str3 = str2; // makes str3 point to same string as str2
  printf("%s\n", str3);

  if (str3 == str2)
    printf("True\n");

  char t[strlen(str2)];

  if (!(str2 == t))
    printf("False\n");
 
  return 0;
}
