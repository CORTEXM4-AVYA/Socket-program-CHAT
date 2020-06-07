#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//include files for defination reg sockets
#include<sys/types.h>
#include<sys/socket.h>

//ip address include file
#include<netinet/in.h>

int main(){
    
    //1.CREATE SOCKET
    int server_socket;
    server_socket=socket(AF_INET,SOCK_STREAM,0);
    //specifying address for socket
    struct sockaddr_in server;
    
    server.sin_family=AF_INET;
    server.sin_port=htons(9002);//connection to port
    server.sin_addr.s_addr=INADDR_ANY;

    //2.BIND TO SPECIFIED IP AND PORT
    bind(server_socket, (struct sockaddr*) &server, sizeof(server));
    
    //3.listen
    listen(server_socket,5);
   
    int client_socket;
  
    client_socket=accept(server_socket,NULL,NULL);
    

    while(1){    
    //3.RECEIVING DATA
        char client_response[256];
        recv(client_socket,client_response,sizeof(client_response),0);
    //printout the server response
        printf("Lilly has sent a message:%s\n",client_response);
    //message
        char message[256];
        printf("Enter the text you want to send:\n\n");
        scanf("%[^\n]%*c",message);
    //4.SEND
        send(client_socket,message,sizeof(message), 0);

   
 
   
    }
    
   close(server_socket);
    return 0;
}
