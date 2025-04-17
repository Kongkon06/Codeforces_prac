#include<stdio.h>
#include<string.h>
#define MAX_LEN 100
void lexical_palindrome(char *s){
    int feq[26]={0},i,j;
    for(i=0;s[i]!='\0';i++){
    feq[s[i]-'a']++;
    }
    for(i=25;i>=0;i--){
        if(feq[i]>0){
            for(j=0;j<feq[i];j++){
                printf("%c",i + 'a');
            }
            printf("\n");
            return;
        }
    }
}
int main(){
   char s[MAX_LEN];
    printf("Enter the string\n");
    scanf("%s",s);
    lexical_palindrome(s);
    return 0;
}
