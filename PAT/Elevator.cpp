#include<cstdio>

int arr[101];

int main(){
    int n,sum=0;
    scanf("%d",&n);
    arr[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=n;i++){
        if(arr[i]>arr[i-1]){
            sum+=(arr[i]-arr[i-1])*6+5;
        }else{
            sum+=(arr[i-1]-arr[i])*4+5;
        }
    }
    printf("%d",sum);
    return 0;
}