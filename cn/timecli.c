#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>
int main()
{
    struct sockaddr_in sa, cli;
    int n, sockfd;
    int len;
    char buff[100];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("\nError in Socket");
        exit(0);
    }
    else
        printf("\nSocket is Opened");
    bzero(&sa, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(5600);
    if (connect(sockfd, (struct sockaddr *)&sa, sizeof(sa)) < 0)
    {
        printf("\nError in connection failed\n");
        exit(0);
    }
    else
        printf("\nconnected successfully\n");
    if (n = read(sockfd, buff, sizeof(buff)) < 0)
    {
        printf("\nError in Reading \n");
        exit(0);
    }
    else
    {
        printf("\nMessage Read \n%s", buff);
    }
    	return 0;
}
