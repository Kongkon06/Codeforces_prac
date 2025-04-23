#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n],i,low=0,high=0,j=0,count=0;
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    high=low=arr[0];
     for(i=1;i<n;i++){
        if(arr[i]<high && arr[i]<low){
            count++;
            low = arr[i];
            j++;
        }else if(arr[i] >high && arr[i]>low){
            count++;
            high = arr[i];
            j++;
        }
    }
         printf("%d",count);
    return 0;
}
