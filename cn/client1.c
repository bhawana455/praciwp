#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdio.h>
#define SERV_TCP_PORT 5035
int main(int argc,char*argv[])                                                                                    
   { int sockfd;                                                                                                                
   struct sockaddr_in serv_addr;
        struct hostent *server;
        char buffer[4096];                                                                                                 
      sockfd=socket(AF_INET,SOCK_STREAM,0);
        serv_addr.sin_family=AF_INET;
        serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
        serv_addr.sin_port=htons(SERV_TCP_PORT);
        printf("Bhawana Priyadarshini\n");
        printf("1841017103\n");
        printf("CSIT D");
        printf("\nReady for sending");
        connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
        printf("\nenter the message to send\n");                                                                           
          printf("\nclient");                                                                                          
          fgets(buffer,4096,stdin);                                                                                          
            write(sockfd,buffer,4096);                                                                                           
            printf("serverecho:%s",buffer);                                                                                     
             printf("\n");                                                                                                     
               close(sockfd);                                                                                                     
                 return 0;
}                              