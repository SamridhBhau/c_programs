#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int main() {
  struct addrinfo hints, *res;
  int sockfd;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  int status;

  if ( (status = getaddrinfo("www.example.com", "3490", &hints, &res))  != 0){
    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
    exit(1);
  }

  sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);


  char name[10];

  gethostname(name, sizeof name);

  printf("HostName: %s\n", name);



  /*
  connect(sockfd, res->ai_addr, res->ai_addrlen);

  shutdown(sockfd, 2);
  close(sockfd);

  if ( (status = connect(sockfd, res->ai_addr, res->ai_addrlen)) == -1 ){
    perror("connect error\n");
    exit(1);
  }
  else {
    printf("Connections successfull\n");
  }
  */


  return 0;
}
