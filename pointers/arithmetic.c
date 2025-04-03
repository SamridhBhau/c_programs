// Memory is like a big array, where a byte is stored at each array index
#include <stdio.h>


int my_strlen(char *s){
  char *e = s;
  while (*e != '\0')
    e++;

  return (e - s);
}

int main() {
  int a[5] = {11, 22, 33, 44, 55};
  int *p = &a[0];

  printf("%d\n", *p); // 11
  printf("%d\n", *(p+1)); // 22
  
  for (int i = 0; i < 5; i++){
    printf("%d\n", *(p + i));   // knows to jump sizeof(int) bytes ahead in memory before it's a int pointer
  }
  // We can subtract two pointers to find difference between them, e.g. we can calculate how many ints there are between two ints (in the above case)
  
  // you can have a pointer that references one past the end of the array without a problem and do math on it but you can't dereference it.

  char *s = "Hello";
  int len = my_strlen(s);
  printf("%d\n", len);

  // a[b] = *(a + b)

  return 0;
}
