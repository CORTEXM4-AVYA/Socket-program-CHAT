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
    int network_socket;
    network_socket=socket(AF_INET,SOCK_STREAM,0);
    //specifying address for socket
    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(9002);//connection to port
    server_address.sin_addr.s_addr=INADDR_ANY;
    
    //2.CONNECT CALL
    int connection_status=connect(network_socket ,(struct sockaddr *) &server_address,sizeof(server_address));
    if(connection_status==-1){
        printf("Error while making an connectiom\n\n");
    }
    //int server_socket;
   // server_socket=accept(network_socket,NULL,NULL);
    while(1){
    
    //4.SEND
        char message[256];
        printf("Enter the message:\n");
        scanf("%[^\n]%*c",message);

        send(network_socket,message,sizeof(message), 0);

    //RECEIVING DATA
        char server_response[256];
        recv(network_socket,server_response,sizeof(server_response),0);
    //printout the server response
        printf("Avinash has sent a message: %s\n",server_response);
   
    
    
      }

    close(network_socket);
    return 0;
}
