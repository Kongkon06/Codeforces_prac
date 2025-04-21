#include<stdio.h>
#include<stdlib.h>
void ConsumeToEOL(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
int main(){
    int n;
    printf("Enter the size\n");
    scanf("%d",&n);
    int arr[n][n];
    int i,j,sum,mid;
    printf("Enter the matrix \n");
    for(i=0;i<n;i++){
        for (j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
            arr[i][j];
        } 
    }
    for(i=0,j=n-1,sum=0,mid=n/2;i<n;i++,j--){
        sum+=arr[i][i];
        sum+=arr[i][j];
        sum+=arr[mid][i];
        sum+=arr[i][mid];
    }
    sum = sum - (3 *arr[mid][mid]);
    printf("%d\n",sum);
    return 0;
}
