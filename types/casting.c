#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int compar(const void *elem1, const void *elem2){
  if (*((const int*)elem1) > *((const int*)elem2)) return 1;
  if ( *((const int*)elem1) < *((const int*)elem2)) return -1;
  return 0;
}

int main() {

  int arr[] = {4, 2, 3, 0, 9, -2, 89, 43, 78};

  qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]),compar);
  
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  int i = 34;
  int *x = &i;

  printf("%p\n", (void*)x);

  long x1 = 3490;
  long *p = &x1;
  unsigned char *c = (unsigned char *)p;
  printf("%c\n", c);

  if (INT_MAX > UCHAR_MAX)
    printf("int greater than unsigned char\n");

  return 0;
}
