#include <stdio.h>

typedef struct {
  char *name;
  int leg_count, speed;
} animal ;

typedef struct {
  int x, y;
} point;


int main() {
  animal z;
  point p = {.x = 20, .y = 30};

  printf("%d, %d\n", p.x, p.y);

  return 0;
}
