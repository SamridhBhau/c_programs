#include <stdio.h>    //system include
#include "myheader.h"   //header file in current directory
#include "../multifile/bar.h" // relative paths

#define PI 3.14159

int main() {
  printf("%f\n", PI);

  return 0;
}

