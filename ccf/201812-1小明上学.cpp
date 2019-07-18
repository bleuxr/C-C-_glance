#include<iostream>
using namespace std;

int main(){
    long long r,y,g,sum,t;
    int n,flag;
    sum=0;
    scanf("%lld%lld%lld",&r,&y,&g);
    scanf("%d",&n);
    while(n--){
        scanf("%d%lld",&flag,&t);
        if(flag==0)
            sum+=t;
        else if(flag==1)
            sum+=t;
        else if(flag==2)
            sum+=(t+r);
    }
    printf("%lld",sum);
    return 0;
}