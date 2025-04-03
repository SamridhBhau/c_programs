/* 
 * structures */
#include <stdio.h>
#include <string.h>

#define NAME_LEN 20 

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
};

void print_part(struct part p){
  printf("Part number: %d\n", p.number);
  printf("Part name: %s\n", p.name);
  printf("Quantity on hand: %d\n", p.on_hand);
}

struct part build_part (int number, const char *name, int on_hand){
  struct part p;
  p.number = number;
  strcpy(p.name, name);
  p.on_hand = on_hand;
  return p;
}

int main(){
  struct part part1 = { .on_hand = 10, .name = "Disk drive", .number = 528 };
  struct part part2 = { 914, "Printer cable", 5};

  part2 = part1; //creates a copy of part1
  part1.number++;
  struct part part3 = build_part(23, "New Part", 8);

  print_part(part1);
  print_part(part3);


  return 0;
}
