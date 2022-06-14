#include <sys/types.h>
#include <sys/socket.h>
#include <netinet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void error(char *msg) {
	perror(msg);
	exit(0);
}

int main(int argc, char **argv) {
	int sock, length, fromlen, n;
	struct sockaddr_in server;
	struct sockaddr_in from;

	char buf[1024];

	if (argc < 2) {
		fprintf(stderr, "ERROR, no port provided\n");
		exit(0);
	}

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0)
		error("Opening socket");

	length = sizeof(server);

	bzero(&server, length);

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = 
