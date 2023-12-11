#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

void gettftpfunction(char *host, char *filename) {
     char rrq_r[1000];
     int socket_fd;
     if ((socket_fd = socket( , , ,)) == -1) {
		 perror("socket error");
		 exit(EXIT_FAILURE);
	 }
     FILE *filen = fopen(filename,'r');
     
}

void puttftpfunction(char *host, char *filename) {
     ///read(STDIN_FILENO, host, strlen(host));
     ///read(STDIN_FILENO, filename, strlen(filename));
}



int main(int argc, char *argv[]) {
	if (argc != 3) {
		perror("argc error");
		exit(EXIT_FAILURE);
	}
	int sock;
    char *host = argv[1];
    char *filename = argv[2];

	struct addrinfo hints = {
        .ai_flags = 0,
        .ai_family = AF_UNSPEC,
        .ai_socktype = SOCK_STREAM, 
        .ai_protocol = 0,
        .ai_addrlen = 0,
        .ai_addr = NULL,
        .ai_canonname = NULL,
        .ai_next = NULL
    };
	
	struct addrinfo *res;
	
    gettftpfunction(host, filename);
    puttftpfunction(host,filename);
	getaddrinfo(host, NULL, &hints, &res);
	
	sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock == -1) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }
    else {
		printf("socket :%d", socket(res->ai_family, res->ai_socktype, res->ai_protocol));
	}
	close(sock);
	freeaddrinfo(res);
    return 0;
}
