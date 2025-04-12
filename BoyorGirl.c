#include<stdio.h>

int main(){
    char ch,arr[100];
    int i,j=0;
    printf("Enter the username \n");
    for(i=0;i<10;i++){
        ch =getchar();
        if(ch=='\n'){
            break;
        }else{
            arr[i]=ch;
            j++;
        }
    }
     if(j%2==0){
        printf("CHAT WITH HER! \n");
     }else{
    printf("GAY \n");
     }
    return 0;
}
