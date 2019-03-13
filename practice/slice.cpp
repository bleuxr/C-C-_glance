#include<iostream>
#include<cstring>
using namespace std;

bool sliceble(int arr[],int len){
    for(int m1=1;m1<len-5;m1++){
        for(int m2=m1+2;m2<len-3;m2++){
            for(int m3=m2+2;m3<len-1;m3++){
                int sum1=0,sum2=0,sum3=0,sum4=0;
                for(int i=0;i<m1;i++)
                    sum1+=arr[i];
                for(int i=m1+1;i<m2;i++)
                    sum2+=arr[i];
                for(int i=m2+1;i<m3;i++)
                    sum3+=arr[i];
                for(int i=m3+1;i<len;i++)
                    sum4+=arr[i];
                if(sum1==sum2&&sum3==sum4&&sum2==sum3)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int A[]={2,5,1,1,1,1,4,1,7,3,7};
    int len=11;
    int A1[] = { 2, 3, 3, 1, 5, 3, 1, 5, 3, 3, 5, 3 }; // true
    int A2[] = { 11, 12, 13, 1, 2, 3, 4, 5 }; // false
    int A3[] = { 4, 4, 1, 8, 1, 8, 1, 1, 8 }; // false
    
    cout<<sliceble(A,len)<<endl;
    cout<<sliceble(A1,12)<<endl;
    cout<<sliceble(A2,8)<<endl;
    cout<<sliceble(A3,9)<<endl;

    return 0;
}