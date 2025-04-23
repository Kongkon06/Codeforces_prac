#include<stdio.h>
#include<stdlib.h>

int RemoveSmallest(){
    int n;
    scanf("%d",&n);
    int arr[n],i,res,j;
    res=n;
    for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        if(arr[i]==-1)continue;
        for(j=i+1;j<n;j++){
        if(abs(arr[i] - arr[j]) <= 1 ){
            if(arr[i]<arr[j]){
                arr[i]=-1;
                res--;
            }else{
                arr[j]=-1;
                res--;
            }
        }
     }
    }
    return res;
};
int main()
{
    int cases;
    scanf("%d",&cases);
    int arr[cases],i,res;
    for(i=0;i<cases;i++){
        res=RemoveSmallest();
        arr[i] = res;
    }
    for(i=0;i<cases;i++){
        switch (arr[i]) {
            case 1:
                printf("YES\n");
            break;
            default:
                printf("NO\n");
            break;
        }
    }
    return 0;
}
