#include<stdio.h>

int forN(int a ,int b, int n){
     if(((a*a) + b) == n){
         return 1;
     }
    return 0;
}
int forM(int a ,int b,int m){
    if((a + (b*b)) == m){
    return 1;
    }
    return 0;
}
int main(){
    int n,m,a=0,b=0,res=0;
    printf("Enter the value of n and m \n");
    scanf("%d",&n);
    scanf("%d",&m);
    for(a=0;a<100;a++){
        for(b=0;b<100;b++){
        if((((a*a) + b) == n) && ((a + (b*b)) == m)){
            res++;
        }       
        }
    }
    printf("%d \n",res);
    return 0;
}
