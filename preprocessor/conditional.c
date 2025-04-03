#include <stdio.h>

#define EXTRA_HAPPY
//#define HELLO
#define MODE_2
#define HAPPY_FACTOR 1

int main() {
  
#ifdef EXTRA_HAPPY    // this gets evaluated during compile time unlike if statements which is evaluated at run time
  printf("I'm extra happy\n");
#endif

#ifndef EXTRA_HAPPY
  printf("I'm just regular\n");
#endif

#ifdef HELLO
  printf("HELLO\n");
#else 
  printf("BYE\n");
#endif


// elifdef elifndef - New in C23
#ifdef MODE_1
  printf("MODE_1\n");
#elifdef MODE_2
  printf("MODE_2\n");
#else 
  printf("None\n");
#endif

#if HAPPY_FACTOR == 0
  printf("I'm not happy\n");
#elif HAPPY_FACTOR == 1
  printf("I'm just regular\n");
#else
  printf("I'm extra happy\n");
#endif

#if !defined PI
  printf("PI NOT DEFINED\n");
#elif defined FOO
  printf("FOO DEFINED\n");
#endif

#undef EXTRA_HAPPY

#ifndef EXTRA_HAPPY
  printf("I'm extra happy\n");
#endif

  return 0;
}
