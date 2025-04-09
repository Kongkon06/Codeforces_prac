#include<stdio.h>
#include<stdbool.h>
#define TEST false
int main(){
    
#if TEST
    printf("test");
#else
    printf("testing");
#endif

return 0;
}
