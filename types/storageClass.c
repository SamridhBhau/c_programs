#include <stdio.h>

static int z = 8; // only functions in this file can access this variable

// Static in Block Scope
void counter(void) {
  static int i;  //default initialized to 0
  static int count = 1; //only initialized once, functions call to counter shared same count variable
  extern int num;  // extern has static storage duration
  printf("This has been called %d time(s)\n", count);
  printf("value of num: %d\n", num);

  num++;
  count++;
}

int main() {
  // auto keyword indicates that this object has automatic storage duration.
  // That is, it exists in the scope in which it is defined, and is automatically deallocated when the scope is exited

  // auto is implicit in block scope
  {
    int a;  // auto is default
    auto int a1; // both declarations are same
  }
  // Always initalize all automatic variables before use

  counter();
  counter();
  counter();
  counter();

  extern int num;  
  // for functions extern is default

  printf("%d\n", num); // 23
  

  // register is a hint to the compiler that this variable is frequently-used, and should be made as fast as possible to access.

  register int a;
  for (a = 0; a < 10; a++){
    printf("%d\n", a);
  }
  // you can't take the address of a register
  // int *p = &a; // Error
  // registers exist in cpu not in ram. so they don't have addresses. Therefore you can't use & with them

  return 0;
}
