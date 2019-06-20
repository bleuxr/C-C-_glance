#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ll r,y,g,n,ans=0,temp=0,k,t;
    scanf("%lld%lld%lld%lld",&r,&y,&g,&n);
    while(n--){
        scanf("%lld%lld",&k,&t);
        if(k==0||k==1)
            temp=t;
        else if(k==2)
            temp=t+r;
        else if(k==3)
            temp=0;
        ans+=temp;
    }
    printf("%lld\n",ans);
    return 0;
}