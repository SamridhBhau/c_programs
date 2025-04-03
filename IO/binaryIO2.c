#include <stdio.h>

int main() {
  FILE *fp;
  unsigned char c;

  fp = fopen("output.bin", "rb");

  while (fread(&c, sizeof(char), 1, fp) > 0)
    printf("%d\n", c);

  fp = fopen("output2.bin", "wb");
  unsigned short v = 0x1234;
  fwrite(&v, sizeof v, 1, fp);

  fclose(fp);

  return 0;
}
