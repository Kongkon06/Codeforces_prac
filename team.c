#include<stdio.h>
int main(){
    int total_problems,i=0,solved_problems=0;
    int col1[100],col2[100],col3[100];
    printf("Enter the number of problem set \n");
    scanf("%d",&total_problems);
    printf("Enter the lines \n");
    while(i<total_problems){
     scanf("%d",&col1[i]);
     scanf("%d",&col2[i]);
     scanf("%d",&col3[i]);
     i++;
    };
    i=0;
 while(i<total_problems){
     if(col1[i]+col2[i]+col3[i] >= 2){
         solved_problems++;
     }
     i++;
    };
printf("Total number of problem that they are able to solved are %d", solved_problems);
    return 0;
}
