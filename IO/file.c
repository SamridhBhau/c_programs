#include <stdio.h>

int main(){
  FILE *fp, *fp2, *fp3, *fp4, *fp5;
  fp = fopen("hello.txt", "r");

  // fgetc keeps track of position in file
  int c;
  while((c = fgetc(fp)) != EOF) {
    printf("%c", c);
  }

  fclose(fp);

  fp2 = fopen("quote.txt", "r");
  char s[1024];
  int linecount = 0;

  while(fgets(s, sizeof s, fp2) != NULL) 
    printf("%d: %s", ++linecount, s);

  fclose(fp2);

  fp3 = fopen("whales.txt", "r");
  char name[1024];
  float length;
  int mass;

  while (fscanf(fp3, "%s %f %d", name, &length, &mass) != EOF)
    printf("%s whale, %d tonnes, %.1f meters\n", name, mass, length);

  fclose(fp3);


  fp4 = fopen("output.txt", "w");
  int x = 32;

  fputc('B', fp4);
  fputc('\n', fp4);
  fprintf(fp4, "x = %d\n", x);
  fputs("Hello, world!\n", fp4);

  fclose(fp4);

  fp5 = stdout;
  fputc('B', fp5);
  fputc('\n', fp5);
  fprintf(fp5, "x = %d\n", x);
  fputs("Hello, world!\n", fp5);


  return 0;
}
