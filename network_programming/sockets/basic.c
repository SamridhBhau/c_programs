#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
  struct sockaddr_in sa;
  struct sockaddr_in6 sa6;

  inet_pton(AF_INET, "10.12.110.57", &(sa.sin_addr));
  inet_pton(AF_INET6, "2001:db8:63b3:1::3490", &(sa6.sin6_addr));
  
  char ip4[INET_ADDRSTRLEN];
  struct sockaddr_in sa2;   // pretend this is loaded with something
  inet_ntop(AF_INET, &(sa2.sin_addr), ip4, INET_ADDRSTRLEN);
  printf("The IPv4 address is: %s\n", ip4);

  char ip6[INET6_ADDRSTRLEN];
  struct sockaddr_in6 sa6_2;  // pretend this is loaded with something
  inet_ntop(AF_INET6, &(sa6_2.sin6_addr), ip6, INET6_ADDRSTRLEN);
  printf("The IPv6 address is: %s\n", ip6);

  
  return 0;
}
