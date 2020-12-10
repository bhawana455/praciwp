#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
printf("bhawana\n");
printf("CSIT\n");
printf("1841017103\n");
int sock;
struct sockaddr_in server;
int server_reply;
int number,i,temp;
sock=socket(AF_INET,SOCK_STREAM,0);
if(sock == -1) {
printf("Couldnot create socket");
}
puts("Socket created");
server.sin_family=AF_INET;
server.sin_addr.s_addr=inet_addr("127.0.0.1");
server.sin_port=htons(8880);
if(connect(sock,(struct sockaddr*)&server,sizeof(server))<0) {
perror("connect failed. Error");
return 1;
}
puts("Connection\n");
printf("Enter number:\n");
scanf("%d",&number);
if(send(sock,&number,sizeof(int),0) < 0)
{
puts("send failed");
return 1;
}
if(recv(sock, &server_reply, sizeof(int),0)<0) {
puts("recv failed");
return 0;
}
puts("Server reply :\n");
printf("%d\n", server_reply);
close(sock);
return 0;
}