/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "include/server.h"

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     // fds returned by socket and accept syscalls
     int sockfd;
     int newsockfd;
     int portno;
     
     // The size of the client's address
     socklen_t clilen;
     
     // Buffer for reading messages into
     char buffer[256];
     
     // Struct for internet address
     struct sockaddr_in serv_addr, cli_addr;
     
     // The return value for read() and write()
     int n;
     
     // Check for port number
    //  if (argc < 2) {
    //      fprintf(stderr,"ERROR, no port provided\n");
    //      exit(1);
    //  }
     
     // Create a new socket, reference later by sockfd
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0)
        error("ERROR opening socket");
     
     // Sets all values in serv_addr zero
     bzero((char *) &serv_addr, sizeof(serv_addr));
     
     // Sets port # to a number passed in (atoi converts srting to int)
    //  portno = atoi(argv[1]);
    portno = PORT;
     
     // Init the server settings
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     
     // Check if the socket can be bound to the address
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0)
              error("ERROR on binding");
              
     // Listen for incoming connections
     listen(sockfd,5);
     
     // Accept an connection
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd,
                 (struct sockaddr *) &cli_addr,
                 &clilen);
     if (newsockfd < 0)
          error("ERROR on accept");
    
     // Init the buffer for reads
     bzero(buffer,256);
     
     // Read messages from the connection, blocks until something can be read
     n = read(newsockfd,buffer,255);
     if (n < 0) error("ERROR reading from socket");
     
     // Display the message/react to the message
     printf("Here is the message: %s\n",buffer);
     
     // Send a message back
     n = write(newsockfd,"I got your message",18);
     if (n < 0) error("ERROR writing to socket");
     
     // Close socket for sending messages
     close(newsockfd);
     
     // Close Sockets for receiving messages`
     close(sockfd);
     return 0;
}
