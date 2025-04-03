#include <stdio.h>

int main() {

  printf("This function: %s\n", __func__);
  printf("This file: %s\n", __FILE__);
  printf("This line: %d\n", __LINE__);
  printf("Compiled on: %s %s\n", __DATE__, __TIME__);

  printf("Standard C compiler: %d\n", __STDC__); 
  printf("Standard C compiler: %ld\n", __STDC_VERSION__); 
  printf("IEEE-754: %d\n", __STDC_IEC_559__);
  printf("IEEE-7540 complex: %d\n", __STDC_IEC_559_COMPLEX__);


  return 0;
}
