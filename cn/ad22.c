#include<stdio.h>
int main(){
    printf("--------------------- Efficient Hall Booking-----------------------\n");
   printf("---------------------- HALL BOOKING SESSION---------------------\n");
   int n;
   printf("enter total events to be take place on same day:");
   scanf("%d",&n);
   int start[n],finish[n];
   for(int q=0;q<n;q++)
   {
      scanf("%d",&start[q]);
       scanf("%d",&finish[q]);
   }
  

   size_t activities = sizeof(start)/sizeof(start[0]);
   int i, j;
  
    printf("Beginning timing           Finish timing\n");
    printf("----------------------------------------\n");
   for(int k=0;k<activities;k++)
   {
      printf(" %-4d                         %-4d \n", start[k],finish[k]);
      
   }
   printf (" Maximum Events which can be booked for Hall are starting from \n");
   i=0;
   printf("   %d \n",start[i]);
   for (j = 1; j <activities; j++){
      if (start[j] >= finish[i]){
         printf ("  %d\n", start[j]);
         i = j;
      }
   }
   return 0;
}