#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int resolveHost(char *hostname, char *ip);

int main(int argc, char *argv[]) {
  if (argc < 2){
    printf("No hostname is given to resolve\n");
    exit(EXIT_FAILURE);
  }

  char *hostname = argv[1];
  char ip[100];
  resolveHost(hostname, ip);
  printf("%s resolved to %s\n", hostname, ip);

  return 0;
}

int resolveHost(char *hostname, char *ip){
  int i;
  struct hostent *hent;
  struct in_addr **addr_list;
  
  // using deprecated function gethostbyname()
  if ( (hent = gethostbyname(hostname)) == NULL ){
    herror("gethostname error");
    return 1;
  }

  addr_list = (struct in_addr **) hent->h_addr_list;

  for (i = 0; addr_list[i] != NULL; i++){
    inet_ntop(AF_INET, addr_list[i], ip, INET_ADDRSTRLEN);
    return 0;
  }
  return 1;
}
