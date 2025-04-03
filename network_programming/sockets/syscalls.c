#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>

int main() {
  struct addrinfo hints, *res;
  int sockfd;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE; // fill in my IP for me

  getaddrinfo(NULL, "3490", &hints, &res);

  sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  bind(sockfd, res->ai_addr, res->ai_addrlen);

  int yes = 1;

  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes) == - 1){
    perror("setsockopt");
    exit(1);
  }

  return 0;
}
