#include<stdio.h>

int Factor(int num,int fac1,int fac2,int fac3,int fac4){
    if(num%fac1 == 0){
        return 1;
    }
    if(num%fac2 == 0){
        return 1;
    }
    if(num%fac2 == 0){
        return 1;
    }
    if(num%fac4 == 0){
        return 1;
    }
    return 0;
};
int main(){
    int k,l,m,n,d,res=0,temp=0;
    scanf("%d",&k);
    scanf("%d",&l);
    scanf("%d",&m);
    scanf("%d",&n);
    scanf("%d",&d);
    for(temp=1;temp<=d;temp++){
        if(Factor(temp,k,l,m,n) == 1){
            res++;
        }
    }
    printf("%d\n",res);
    return 0;
}
