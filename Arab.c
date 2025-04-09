#include<stdio.h>

typedef enum {
    RED,
    GREEN,
    YELLOW
} Color;
int main(){
    Color c = RED;
    if(c == RED){
        printf("RED");
    }
    return 0;
}
