#include <stdio.h>

struct cabin_information {
  int window_count;
  int o2_level;
};

struct spaceship {
  char *manufacturer;
  struct cabin_information ci;
};

int main() {
  struct spaceship s = {
    .manufacturer = "General Products",
    .ci.window_count = 8,
    .ci.o2_level = 21
  };

  struct spaceship s1 = {
    .manufacturer = "General Products", 
    .ci = {
      .window_count = 8,
      .o2_level = 21
    }
  };

  

  printf("%s: %d seats, %d%% oxygen\n", 
         s.manufacturer, s.ci.window_count, s.ci.o2_level);

  return 0;
}
