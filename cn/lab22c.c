#include<arpa/inet.h>
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
int sock;
struct sockaddr_in server;
int size=10;
int server_reply[size];
int number[size],i,temp;
printf("enter elements\n");
for(int x=0;x<size;x++)
{
scanf("%d",&number[x]);
}
sock=socket(AF_INET,SOCK_STREAM,0);
if(sock == -1)
{
printf("could not create socket");
}
puts("socket created");
server.sin_addr.s_addr=inet_addr("127.0.0.1");
server.sin_family=AF_INET;
server.sin_port=htons(8880);
if(connect(sock,(struct sockaddr*)&server,sizeof(server)) < 0){
perror("connect failed.error");
return 1;
}
printf("bhawana\n");
printf("CSIT\n");
printf("1841017103\n");
puts("connection to server was successful\n");
if(send(sock,&number,size * sizeof(int),0) < 0)
{
puts("send failed");
return 1;
}
if(recv(sock,&server_reply,size * sizeof(int),0)< 0)
{
puts("recv failed");
return 0;
}
puts("sorted numbers");
for(i=0;i<size;i++)
{
printf("%d ",server_reply[i]);
}
printf("\n");
close(sock);
return 0;
}