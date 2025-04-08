#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int i = 5;
  int arr[10];
  assert(0 <= i && i < 10);
  arr[i] = 0;

  errno = 0;
  int x = -1;
  double y = sqrt(x);

  if (errno != 0){
    perror("sqrt error");
    puts(strerror(errno));
    exit(EXIT_FAILURE);
  }


  return 0;
}
