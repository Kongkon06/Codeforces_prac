#include<stdio.h>

int main(){
    int size,pos;
    if(scanf("%d%d",&size,&pos)!= 2){
        printf("Bad input Try again later\n");
        return 0;
    };
    int arr[size],i,j;
    for (i=0;i<size;i++) {
        scanf("%d",&arr[i]);
    }
    for (i=0,j=0;i<size;i++) {
       if(arr[i] != 0 && arr[i]>=arr[pos-1]){
            j++;
       }
    }
        printf("%d",j); 
    return 0;
}
