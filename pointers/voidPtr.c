#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct animal {
  char *name;
  int leg_count;
};

int compare(const void *elem1, const void *elem2){

  const struct animal *animal1 = elem1;
  const struct animal *animal2 = elem2;

  if (animal1->leg_count > animal2->leg_count)
    return 1;

  if (animal1->leg_count < animal2->leg_count)
    return -1;

  return 0;
}

int main() {
  char s[] = "Hello";
  char t[100];

  memcpy(t, s, 6); // Copy 6 bytes including the NUL character ('\0')
  printf("%s\n", t);


  struct animal a[4] = {
    {.name="Dog", .leg_count=4},
    {.name="Monkey", .leg_count=2},
    {.name="Antelope", .leg_count=4},
    {.name="Snake", .leg_count=0}
  };

  qsort(a, 4, sizeof(struct animal), compare);

  for (int i = 0; i < 4; i++)
    printf("%d: %s\n", a[i].leg_count, a[i].name);

  return 0;
}
