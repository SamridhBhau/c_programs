#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};


int main() {
  struct node *head;

  head = malloc(sizeof(struct node));
  head->data = 11;
  head->next = malloc(sizeof(struct node));
  head->next->data = 12;
  head->next->next = malloc(sizeof(struct node));
  head->next->next->data = 22;
  head->next->next->next = NULL;

  for (struct node *cur = head; cur != NULL; cur = cur->next){
    printf("%d\n", cur->data);
  }


  return 0;
}
