#include <sys/types.h>
#include <sys/socket.h>   
#include <netinet/in.h>
#include <netdb.h>
#include <string>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>


using namespace std;

int main(int argc, char *argv[]) {

	int sockfd; // socket file descriptor 
	int portno = 8000; // port number
	struct sockaddr_in serv_addr;
	struct hostent *server;


	const char * ip = "192.168.100.18";
	//argv[1] = 192.168.100.18; // ip of server
	//argv[2] = portno; // port number

	sockfd = socket(AF_INET, SOCK_STREAM, 0); // generate file descriptor 
	if (sockfd < 0) {
		perror("ERROR opening socket");
	}

	server = gethostbyname(ip); //the ip address (or server name) of the listening server.
	if (server == NULL) {
		fprintf(stderr,"ERROR, no such host\n");
		exit(0);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);

	if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0){
		perror("ERROR connecting"); 
	}

	char rbuff[256];
	int rbytes; 

	//rbytes = read(sockfd, rbuff, sizeof(rbuff)); // read from socket and store the msg into buffer
	rbytes = recv(sockfd, rbuff, sizeof(rbuff), 0); // similar to read(), but return -1 if socket closed
	rbuff[rbytes] = '\0'; // set null terminal
	printf("Message: %s\n", rbuff);

	int wbytes;
	char * wbuff; 
	string str = "My Message!!";
	wbuff = (char *)str.c_str(); // convert from string to c string, has to have \0 terminal 

	wbytes = write(sockfd, wbuff, strlen(wbuff));
	if(wbytes < 0) {
		perror("Cannot write to socket");
	} 
}