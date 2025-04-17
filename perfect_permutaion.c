#include<stdio.h>
int main(){
    int num,p[100],i;
    printf("Enter the number\n");
    scanf("%d",&num);
    if(num%2!=0){
        printf("-1");
    };
    for(i=1;i<=num;i+=2){
        p[i] = i+1;
        p[i+1] =i;
    };
    printf("The permutation is \n");
    for(i=1;i<=num;i++){
        printf("%d ",p[i]);
    };
    return 0;
}
