#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

struct node{
    int rs,nu;
    node(int rs,int nu):rs(rs),nu(nu){};
};

int getnum(string& s, int m,int len){
    int num=0;
    for(int i=m;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            num*=10;
            num+=(s[i]-'0');
        }else
        {
            break;
        }
        
    }
    return num;
}

int main(){
    int t,n,len,flag,num;
    string s;
    scanf("%d%d",&t,&n);
    getchar();
    for(int i=0;i<t;i++){
        queue<node>* pro=new queue<node>[n];
        for(int j=0;j<n;j++){
            getline(cin,s);
            len=s.length();
            for(int l=0;l<len;l++){
                if(s[l]=='S'){
                    l++;
                    num=getnum(s,l,len);
                    pro[j];
                    pro[j].push(node(1,num));
                }
                else if(s[l]=='R'){
                    l++;
                    num=getnum(s,l,len);
                    pro[j].push(node(0,num));
                }
            }
        }
        flag=0;
        while(!flag){
            flag=1;
            for(int j=0;j<n;j++){
                if(!pro[j].empty()&&pro[j].front().rs){
                    if(!pro[pro[j].front().nu].empty()&&!pro[pro[j].front().nu].front().rs&&pro[pro[j].front().nu].front().nu==j){
                        pro[pro[j].front().nu].pop();
                        pro[j].pop();
                        flag=0;
                    }
                }
            }
        }
        flag=0;
        for(int j=0;j<n;j++){
            if(!pro[j].empty()){
                flag=1;
                break;
            }
        }
        delete[] pro;
        printf("%d\n",flag);
    }
    return 0;
}