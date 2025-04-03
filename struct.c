#include <stdio.h>

struct car {
  char *name;
  float price;
  int speed;
};

void set_price(struct car *c, float new_price);

int main(){
  struct car saturn = {"Saturn SL/2", 16000.99, 175};
  struct car saturn2 = {.name = "Saturn SL/2",.speed = 175 , .price = 16000.99, };
  printf("Name:   %s\n", saturn.name);
  printf("Price:   %f\n", saturn.price);
  printf("Speed:   %d\n", saturn.speed);

  return 0;
}

void set_price(struct car *c, float new_price){
  c->price = new_price;
}
