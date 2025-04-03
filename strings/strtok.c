#include <stdio.h>
#include <string.h>


int main() {
  char ips[] = "127.0.0.1, 192.0.2.1, 172.16.254.1";
  char *saveptr1;
  char *saveptr2;

  char *tok = strtok_r(ips, ", ", &saveptr1);
  while (tok != NULL){
    printf("Token: %s\n", tok);

    char *subtok = strtok_r(tok, ".", &saveptr2);

    while(subtok != NULL){
      printf("Subtoken: %s\n", subtok);
      subtok = strtok_r(NULL, ".", &saveptr2);
    }

    tok = strtok_r(NULL, ", ", &saveptr1);
  }

  return 0;
}
