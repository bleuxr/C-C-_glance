#include<iostream>
using namespace std;

union{
    char flag[3];
    short value;
}sampleUnion;

struct{
    char flag[3];
    short value;
}sampleStruct;

int main(){
    cout<<sizeof(sampleUnion)<<endl;
    cout<<sizeof(sampleStruct)<<endl;
}
