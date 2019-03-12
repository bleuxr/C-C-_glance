#include<stdio.h>

//bug sizeof() doesn't work
// int sum_error(int a[]){
//     int ans=0;
//     for(int i=0;i<sizeof(a);i++)
//         ans+=a[i];
//     return ans;
// }

int sum(int* a,int n){
    int ans=0;
    for(int i=0;i<n;i++)
        ans+=a[i];
    return ans;
}

int sum_1(int* begin,int* end){
    int n=end-begin;
    int ans=0;
    for(int i=0;i<n;i++)
        ans+=begin[i];
    return ans;
}

int sum_2(int* begin,int* end){
    int *p=begin;
    int ans=0;
    for(int *p=begin;p!=end;p++)
        ans+=*p;
    return ans;
}

int main()
{
    int a[]={1,2,3,4};
    printf("%d\n",sum(a+1,3));
    return 0;
}