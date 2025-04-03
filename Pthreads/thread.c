#include <stdio.h>
#include <pthread.h>

typedef struct {
  int a;
  int b;
} myarg_t;

void *mythread(void *arg){
  myarg_t *args = (myarg_t *)arg;
  printf("%d %d\n", args->a, args->b);
  return NULL;
}

int main() {
  pthread_t p;
  myarg_t args = { .a = 10, .b = 20 };

  int rc = pthread_create(&p, NULL, mythread, &args);

  printf("Inside main function\n");

  return 0;
}
