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

class Client {
	private:
		int sockfd; //descriptor de archivo socket
		int portno = 8000; //numero de puerto
		struct sockaddr_in serv_addr;
		struct hostent *server;
		const char * ip = "192.168.100.18";  

	public:
		send(string mensaje) {
			sockfd = socket(AF_INET, SOCK_STREAM, 0); //generar el descriptor de archivo
			if(sockfd < 0) {
				perror("ERROR abriendo socket");
			}
			
			server = gethostbyname(ip); //la direccion de ip del servidor
			if(server == NULL) {
				fprintf(stderr,"ERROR, no existe ese host\n");
				exit(0);
			}
			
			bzero((char *) &serv_addr, sizeof(serv_addr));
			serv_addr.sin_family = AF_INET;
			bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
			serv_addr.sin_port = htons(portno);
			
			if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0){
				perror("ERROR conectandose"); 
			}
			
			//escribir al socket
			int wbytes;
			char * wbuff; 
			string str = mensaje;
			wbuff = (char *)str.c_str(); //se convierte de string a c string
			
			wbytes = write(sockfd, wbuff, strlen(wbuff));
			if(wbytes < 0) {
				perror("No se le puede escribir al socket");
			} 
		}

		receive() {
			sockfd = socket(AF_INET, SOCK_STREAM, 0); //generar el descriptor de archivo
			if(sockfd < 0) {
				perror("ERROR abriendo socket");
			}
			
			server = gethostbyname(ip); //la direccion de ip del servidor
			if(server == NULL) {
				fprintf(stderr,"ERROR, no existe ese host\n");
				exit(0);
			}
			
			bzero((char *) &serv_addr, sizeof(serv_addr));
			serv_addr.sin_family = AF_INET;
			bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
			serv_addr.sin_port = htons(portno);
			
			if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0){
				perror("ERROR conectandose"); 
			}
			
			//leer del socket
			char rbuff[256];
			int rbytes; 
			
			rbytes = recv(sockfd, rbuff, sizeof(rbuff), 0); //parecido a read(), pero devuelve -1 si el socket cerro
			rbuff[rbytes] = '\0'; //se setea terminal nula
			printf("Message: %s\n", rbuff);
			
		}
	
	
}

int main(int argc, char *argv[]) {

	Client cliente;
	cliente.send("hello world");
	
}