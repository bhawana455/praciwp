#include<stdio.h>
int main(){
    printf("--------------------- TIME PLANNER-----------------------\n");
   printf("----------------NIGHT HALL BOOKING SESSION---------------------\n");
   int start[] = {1 , 5 , 12};
   int finish[] = {10, 13, 23};
  
   size_t activities = sizeof(start)/sizeof(start[0]);
   int i, j;
  
    printf("Beginning timing           Finish timing\n");
    printf("----------------------------------------\n");
   for(int k=0;k<activities;k++)
   {
      printf(" %-4dam                          %-4dpm\n", start[k],finish[k]);
      
   }
   printf ("Events which can be booked for Hall are starting from \n");
   i=0;
   printf("   %dam \n",start[i]);
   for (j = 1; j <activities; j++){
      if (start[j] >= finish[i]){
         printf ("  %dam\n", start[j]);
         i = j;
      }
   }
   return 0;
}