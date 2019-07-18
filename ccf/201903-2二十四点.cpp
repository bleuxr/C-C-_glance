#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    int n,p,q;
    string s;
    stack<int> num;
    stack<char> op;
    scanf("%d",&n);
    while(n--){
        cin>>s;
        for(int i=0;i<7;i++){
            if(s[i]>'0'&&s[i]<='9'){
                num.push(s[i]-'0');
            }
            else if(s[i]=='+'){
                op.push('+');
            }
            else if(s[i]=='-'){
                i++;
                num.push((-1)*(s[i]-'0'));
                op.push('+');
            }
            else if(s[i]=='x'){
                i++;
                p=num.top();
                num.pop();
                num.push(p*(s[i]-'0'));
            }
            else if(s[i]=='/'){
                i++;
                p=num.top();
                num.pop();
                num.push(p/(s[i]-'0'));
            }
        }
        while(!op.empty()){
            q=num.top();
            num.pop();
            p=num.top();
            num.pop();
            op.pop();
            num.push(q+p);
        }
        cout<<(num.top()==24?"Yes":"No")<<endl;
    }
    return 0;
}