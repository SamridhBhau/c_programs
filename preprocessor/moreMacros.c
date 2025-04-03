#include <stdio.h>
#include <stdlib.h>

int main() {
  int a[] = {
  #embed "/dev/random" limit(5) // not in gcc yet
  };

  int x = 
    #embed "foo.dat" if_empty(999)
  ; 

  printf("%d\n", x);

  int b[] = {
    #embed "foo.dat" 
  };
  printf("%d\n", b[0]);

  for (int i = 0; i < 5; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");

  int nums[] = {
  #if __has_embed("bar.dat")
      #embed "foo.dat" limit(5)
  #else
      140, 178, 120
  #endif
  };

  printf("%d\n", nums[0]);
  #line 300 "newfile"
  printf("%d\n" , __LINE__); // 300
  printf("%d\n" , __LINE__); // 301
  printf("%s\n", __FILE__); // newfile


  return 0;
}
