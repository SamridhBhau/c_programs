#include <stdio.h>

void foo(float arr[4]){
  printf("%zu\n", sizeof arr); //when you pass array you only pass pointer to the first element
                               // and that's what sizeof measures
}

void display(int *a, int len){
  for (int i = 0; i < len; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");
}

void doubleArray(int *a, int len){
  for(int i = 0; i < len; ++i)
    a[i] *= 2;
}

int main(){
  
  int i, j;
  float arr[4];
  arr[0] = 3.4;
  arr[1] = 2.56;
  arr[2] = 2.31;
  arr[3] = 7.38;

  for (i = 0; i < 4; ++i){
    printf("%f\n", arr[i]);
  }

  printf("%zu\n", sizeof arr/sizeof(float));

  printf("%zu\n", sizeof arr);
  foo(arr);

  int arr2[] = {12, 2, 5, 79};

  for (i = 0; i < 4; ++i){
    printf("%d ", arr2[i]);
  }
  printf("\n");

  int arr3[10] = {0}; //set an entire array to zero
  
  int a[5] = {[2]=3, 2, 1}; // 0 0 3 2 1
  for(i = 0; i < 5; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");

  int mat[3][3] = {[0][0] = 1, [1][1] = 1, [2][2] = 1};
  for (i = 0; i < 3; ++i){
    for (j = 0; j < 3; ++j){
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }

  int *p = a; //

  display(a, sizeof a/sizeof(int));

  doubleArray(a, sizeof a/sizeof(int));
  display(a, sizeof a/sizeof(int));


  return 0;
}
