#include <iostream>

using namespace std;

typedef long long ll;

ll r,y,g;

ll add (ll k,ll t,ll time){
    if(k==0) return t;
    if(k==1)
        t=r-t;
    else if(k==2)
        t=r+g+y-t;
    else if(k==3)
        t=r+g-t;
    
    t=(t+time)%(r+g+y);
    if(0<=t&&t<r)
        return r-t;
    else if(r<=t&&t<r+g+y)
        return 0;
    else if(r+g<=t&&t<r+g+y)
        return (r+g+y-t+r);
}

int main(){
    ll n,ans=0,k,t;
    scanf("%lld%lld%lld%lld",&r,&y,&g,&n);
    while(n--){
        scanf("%lld%lld",&k,&t);
        ans+=add(k,t,ans);
    }
    printf("%lld\n",ans);
    return 0;
}