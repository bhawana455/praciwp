#include<arpa/inet.h>
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
void bubble_sort(int[],int);
int main(int argc,char* argv[])
{
printf("bhawana\n");
printf("CSIT\n");
printf("1841017103\n");
int socket_desc,client_sock,c,read_size;
struct sockaddr_in server,client;
int message[10],i;
socket_desc=socket(AF_INET,SOCK_STREAM,0);
if(socket_desc == -1)
{
printf("couldnot create socket");
}
puts("socket creation done");
server.sin_family=AF_INET;
server.sin_addr.s_addr=INADDR_ANY;
server.sin_port=htons(8880);
if(bind(socket_desc,(struct sockaddr*)&server,sizeof(server))<0)
{
perror("bind failed.error");
return 1;
}
puts("server is binded");
listen(socket_desc,3);
puts("waiting for client to connect\n");
c=sizeof(struct sockaddr_in);
client_sock=accept(socket_desc,(struct sockaddr*)&client,(socklen_t*)&c);
if(client_sock <0)
{
perror("accept failed");
return 1;
}
puts("connection accepted");
while((read_size=recv(client_sock, &message,10*sizeof(int),0)) >0)
{
bubble_sort(message,10);
write(client_sock, &message,10 * sizeof(int));
}
if(read_size == 0){
puts("client disconnected");
}
else if(read_size == -1){
perror("recv failed");
}
return 0;
}
void bubble_sort(int list[],int n)
{
int c,d,t;
for(c=0;c<(n-1);c++){
for(d=0;d<n-c-1;d++){
if(list[d]>list[d+1]){
t=list[d];
list[d]=list[d+1];
list[d+1]=t;
}
}
}
}
