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
    int i,j,sum,col_mid,row_mid;
    printf("Enter the matrix \n");
    for(i=0;i<n;i++){
        for (j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
            arr[i][j];
        } 
    }
    for(i=0,j=n-1,sum=0,col_mid=n/2;i<n;i++,j--){
        sum+=arr[i][i];
        sum+=arr[i][j];
        sum+=arr[col_mid][i];
        sum+=arr[i][col_mid];
    }
    sum = sum - (3 *arr[col_mid][col_mid]);
    printf("%d\n",sum);
    return 0;
}
