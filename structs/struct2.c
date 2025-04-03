#include <stdio.h>

struct passenger {
  char *name;
  int covid_vaccinated;
};

#define MAX_PASSENGERS 8

struct spaceship {
  char *manufacturer; 
  struct passenger passenger[MAX_PASSENGERS];
};

#define MAX_SUBJECTS 2

struct student {
  char *name;
  int marks[MAX_SUBJECTS];
};

int main(void) {
  struct spaceship s = {
    .manufacturer = "General Products",
    .passenger =  {
      [0].name = "Lewis",
      [0].covid_vaccinated = 0,
      [7] = {.name = "Brown", .covid_vaccinated = 1},
    }
  };
  printf("Passengers for %s ship\n", s.manufacturer);

  for(int i = 0; i < MAX_PASSENGERS; i++){
    if (s.passenger[i].name != NULL){
      printf(" %s (%svaccinated)\n", 
             s.passenger[i].name,
             s.passenger[i].covid_vaccinated? "" : "not ");
    }
  }

  struct student s1 = {
    .name = "John",
    .marks = {
      [0] = 20,
      [1] = 22
    }
  };

  printf("Name: %s\n", s1.name);

  for (int i = 0; i < MAX_SUBJECTS; i++){
    printf(" %d\n", s1.marks[i]);
  }

  return 0;
}
