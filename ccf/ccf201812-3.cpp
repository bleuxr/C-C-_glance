#include <iostream>
#include <list>
#include <string>

using namespace std;

struct IP{
    string ip;
    int len;
    IP(){}
    IP(string ip,int len):ip(ip),len(len){}
    bool operator <(const IP &a)const{
        return ip==a.ip?(len<a.len):(ip<a.ip);
    }
};

list<IP>l;

string itos(int n){
    string res="00000000";
    int k=7;
    while(n){
        res[k--]=n%2+'0';
        n/=2;
    }
    return res;
}

void read(){
    string ip="";
    char ch;
    int len=0,k=0,val=0;
    bool flag=false;
    while((ch=getchar())!='\n'){
        if(ch=='.'){
            k++;
            ip+=itos(val);
            val=0;
        }
        else if(ch=='/'){
            ip+=itos(val);
            val=0;
            flag=true;
        }
        else{
            val=val*10+ch-'0';
        }
    }
    len=(flag?val:(k+1)*8);
    if(!flag) ip+=itos(val);
    while(k<3){
        ip+=itos(0);
        k++;
    }
    l.push_back(IP(ip,len));
}

int main(){
    int n,i;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
        read();
    l.sort();
    for(list<IP>::iterator cur=l.begin(),next;cur!=l.end();){
        next=cur;
        next++;
        if(next==l.end()) break;
        for(i=0;i<cur->len;i++)
            if(cur->ip[i]!=next->ip[i])
                break;
        if(i==cur->len)
            l.erase(next);
        else
            cur++;       
    }
    for(list<IP>::iterator cur=l.begin(),next;cur!=l.end();){
        next=cur;
        next++;
        if(next==l.end()) break;
        if(cur->len==next->len&&cur->len>0&&cur->ip[cur->len-1]=='0'){
            for(i=0;i<cur->len-1;i++)
                if(cur->ip[i]!=next->ip[i])
                    break;
            if(i==cur->len-1){
                l.erase(next);
                cur->len--;
                if(cur!=l.begin()){
                    cur--;
                    continue;
                }
            }
        }
        cur++;
    }
    for(list<IP>::iterator cur=l.begin();cur!=l.end();cur++){
        for(i=7;i<32;i+=8){
            int temp=0;
            for(int j=i-7;j<=i;j++)
                temp=temp*2+cur->ip[j]-'0';
            printf("%d",temp);
            if(i!=31) printf(".");
        }
        printf("/%d\n",cur->len);
    }
    return 0;
}