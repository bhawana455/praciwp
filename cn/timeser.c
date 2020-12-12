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
    struct sockaddr_in sa;
    struct sockaddr_in cli;
    int sockfd, conntfd;
    int len, ch;
    char str[100];
    time_t tick;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("error in socket\n");
        exit(0);
    }
    else
        printf("Socket opened\n");
    bzero(&sa, sizeof(sa));
    sa.sin_port = htons(5600);
    sa.sin_addr.s_addr = htonl(0);
    if (bind(sockfd, (struct sockaddr *)&sa, sizeof(sa)) < 0)
    {
        printf("Error in binding\n");
    }
    else
        printf("Binded Successfully\n");
    listen(sockfd, 50);
    for (;;)
    {
        len = sizeof(ch);
        conntfd = accept(sockfd, (struct sockaddr *)&cli, &len);
        printf("Accepted \n");
        tick = time(NULL);

     int hours, minutes, seconds, day, month, year;
     time_t now;
     time(&now);
     struct tm *local = localtime(&now);
 
    hours = local->tm_hour;          
    minutes = local->tm_min;         
    seconds = local->tm_sec;         
 
    day = local->tm_mday;            
    month = local->tm_mon + 1;       
    year = local->tm_year + 1900;    
 
    printf("%02d:%02d:%02d  ", hours, minutes, seconds);
    printf("%02d/%02d/%d\n", day, month, year);

    snprintf(str, sizeof(str), "%02d:%02d:%02d  %02d/%02d/%d\n",hours, minutes, seconds, day, month, year);
	//snprintf(str, sizeof(str), "%s", ctime(&tick));
        //printf("%s", str);
        write(conntfd, str, 100);
    }
}
