#include<iostream>
#include<string>
#include<vector>
using namespace std;
char a[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
    string str;
    int sum=0;
    cin>>str;
    for(int i=0;i<str.length();i++){
        sum+=str[i]-'0';
    }
    vector<int> v;
    int count=0;
    do{
        v.push_back(sum%10);
        sum/=10;
        count++;
    }while(sum!=0);
    for(int i=count-1;i>=0;i--){
        if(i!=count-1) printf(" ");
        printf("%s",a[v[i]]);
    }
    return 0;
}