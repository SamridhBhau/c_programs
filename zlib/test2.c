#include <stdio.h>
#include <zlib.h>
#include <string.h>
#include <stdlib.h>

#define CHUNK 16384

int main(){
  char *msg = "orange";
  z_stream strm;
  int have;
  int ret;
  unsigned char *out = malloc(CHUNK);
  memset(out, 0,CHUNK);

  strm.zalloc = Z_NULL;
  strm.zfree = Z_NULL;
  strm.opaque = Z_NULL;

  ret = deflateInit2(&strm, Z_DEFAULT_COMPRESSION, Z_DEFLATED, 0x1F, 8, Z_DEFAULT_STRATEGY);

  strm.next_in = (unsigned char *)msg;
  strm.avail_in = strlen(msg);

  strm.avail_out = CHUNK;
  strm.next_out = out;
  deflate(&strm, Z_FINISH);
  have = CHUNK - strm.avail_out;
  fwrite(out, sizeof(char), have, stdout);

  deflateEnd(&strm);
  return Z_OK;

}
