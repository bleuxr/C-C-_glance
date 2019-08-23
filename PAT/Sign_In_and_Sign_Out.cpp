#include<iostream>
#include<string>
using namespace std;

const int INF=1000000;

int converttime(int h,int m,int s){
    return 3600*h+60*m+s;
}

int main(){
    int n,h,m,s;
    int temp,unlock,lock;
    string str,unlockid,lockid;
    unlock=INF;
    lock=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>str;
        scanf("%d:%d:%d",&h,&m,&s);
        temp=converttime(h,m,s);
        if(temp<unlock){
            unlock=temp;
            unlockid=str;
        }
        scanf("%d:%d:%d",&h,&m,&s);
        temp=converttime(h,m,s);
        if(temp>lock){
            lock=temp;
            lockid=str;
        }
    }
    cout<<unlockid<<" "<<lockid<<endl;
    return 0;
}