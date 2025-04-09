#include<stdio.h>
#include<conio.h>

int main(){
    int i=0,j=0,n=6;
    for(i=1;i<n;i++){
        for(j=1;j<n;j+=i){
            printf("%d",j);
        };
    };
    return 0;
}
