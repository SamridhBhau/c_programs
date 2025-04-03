#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>


int main(int argc, char *argv[]){
  if (argc < 2){
    printf("No hostname given to resolve\n");
    exit(1);
  }

  char *hostname = argv[1];

  struct addrinfo *servinfo;
  struct addrinfo hints;
  memset(&hints, 0, sizeof hints);

  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  int status;
  if ( (status = getaddrinfo(hostname, "http", &hints, &servinfo)) != 0 ){
    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
    exit(1);
  }


  printf("IP addresses for %s: \n\n", hostname);
  for (struct addrinfo *ptr = servinfo; ptr != NULL; ptr = ptr->ai_next){
    void *addr;
    char *ipver;
    char ipstr[INET6_ADDRSTRLEN];

    if (ptr->ai_family == AF_INET){
      struct sockaddr_in *ip4 = (struct sockaddr_in *)ptr->ai_addr;
      addr = &(ip4->sin_addr);
      ipver = "IPv4";
    }
    else {
      struct sockaddr_in6 *ip6 = (struct sockaddr_in6 *)ptr->ai_addr;
      addr = &(ip6->sin6_addr);
      ipver = "IPv6";
    }

    inet_ntop(ptr->ai_family, addr, ipstr, sizeof ipstr);
    printf("  %s: %s\n", ipver, ipstr);

  }

  freeaddrinfo(servinfo);

  return 0;
}
