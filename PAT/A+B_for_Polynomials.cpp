#include<iostream>
using namespace std;

int main(){
    int k,n;
    double a;
    double arr[1001]={0};
    for(int i=0;i<2;i++){
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            scanf("%d%lf",&n,&a);
            // printf("%d%lf",n,a);
            arr[n]+=a;
        }
    }
    k=0;
    for(int i=0;i<1001;i++){
        if(arr[i]!=0)
            k++;
    }
    printf("%d",k);
    for(int i=1000;i>=0;i--){
        if(arr[i]!=0)
            printf(" %d %0.1lf",i,arr[i]);
    }
    return 0;
}