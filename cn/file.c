#include<stdio.h>
#define EVEN 0
#define ODD 1
int main()
{
    int i=0;
    switch(i)
    {
        case '0': printf("ok");
                     break;
            case '1': printf("hello");
                     break;          
     default: printf("bye");
    }
  return 0;
}