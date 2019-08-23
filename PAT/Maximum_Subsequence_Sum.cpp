#include<cstdio>
#include<algorithm>
using namespace std;

const int INF=1000000;
int arr[10000],dp[10000];

int main(){
    int n,first,last,temp,max;
    first=0;
    last=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    dp[0]=arr[0];
    max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i]+dp[i-1]){
            dp[i]=arr[i];
            temp=i;
        }else{
            dp[i]=arr[i]+dp[i-1];
        }
        if(dp[i]>max){
            max=dp[i];
            first=temp;
            last=i;
        }
    }

    if(max<0){
        printf("0 %d %d",arr[0],arr[n-1]);
    }else{
        printf("%d %d %d",max,arr[first],arr[last]);
    }
    return 0;
}