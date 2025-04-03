#include <stdio.h>

void swap(int *restrict a, int *restrict b){
  int t;
  t = *a;
  *a = *b;
  *b = t;
}

int main() {
  const int x = 2; 

  int n = 23;

  const int *p = &n; // we can change p, but we cannot change what p points to 
  int n1 = 21; 
  p = &n1; // valid

  // *p = 2; // invalid
  
  int * const p1 = &n; // we can modify what p1 pointers to but we can't modify p
  *p1 = 2; //valid
  
  // p1 = &n;  //invalid

  const int *const p2 = &n1; // cannot modify both p2 and what p2 points to

  char **p3;
  // p3++     -- ok 
  // (*p3)++  -- ok 

  char ** const p4;
  // p4++     -- Error! 
  // (*p4)++  -- ok 

  char *const *p5;
  // p5++     -- ok
  // (*p5)++  -- Error 

  char *const *const p6;
  // p6++     -- Error
  // (*p6)++  -- Error
  
  const int n2 = 20;
  int *pt = &n2;  // discards constness of const int *
  *pt = 40; // undefined behaviour

  printf("%d\n", x);

  int n3 = 10, y = 20;
  swap(&n3, &y);
  
  swap(&n3, &n3);

  return 0;
}
