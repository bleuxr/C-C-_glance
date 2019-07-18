#include<iostream>
using namespace std;

long long r,y,g;

long long addtime(int flag,long long t,long long sum){
    long long time;
    if(flag==0)
        return t;
    else if(flag==1)
        time=(r-t+sum)%(r+y+g);
    else if(flag==2)
        time=(r+g+y-t+sum)%(r+y+g);
    else if(flag==3)
        time=(r+g-t+sum)%(r+y+g);
    if(time<r)
        return r-time;
    else if(time<r+g)
        return 0;
    else if(time<r+g+y)
        return r+g+y-time+r;
    return 0;
}

int main(){
    long long sum,t;
    int n,flag;
    sum=0;
    scanf("%lld%lld%lld",&r,&y,&g);
    scanf("%d",&n);
    while(n--){
        scanf("%d%lld",&flag,&t);
        sum+=addtime(flag,t,sum);
    }
    printf("%lld",sum);
    return 0;
}