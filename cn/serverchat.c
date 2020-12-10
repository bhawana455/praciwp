#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int welcomeSocket,newSocket,portNum,clientLen,nBytes;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;
    int i;
    welcomeSocket=socket(PF_INET,SOCK_STREAM,0);
    portNum=7891;
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons(portNum);
    serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero,'\0',sizeof serverAddr.sin_zero);
    bind(welcomeSocket,(struct sockaddr*)&serverAddr,sizeof (serverAddr));
    if(listen(welcomeSocket,5)==0)
    printf("listening\n");
    else
    printf("error\n");
    addr_size=sizeof serverStorage;
    while (1)
    {
        newSocket= accept(welcomeSocket,(struct sockaddr*)&serverStorage,&addr_size);
        nBytes=1;
        while (nBytes!=0)
        {
            nBytes=recv(newSocket,buffer,1024,0);
             send(newSocket,buffer,nBytes,0);
        }
        
          exit(0);
          close(newSocket); 
    }
    return 0;
    
}