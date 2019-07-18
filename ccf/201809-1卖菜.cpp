#include<iostream>

using namespace std;

int main(){
    int n;
    int arr[1001];
    int arr2[1001];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    arr2[0]=(arr[0]+arr[1])/2;
    for(int i=1;i<n-1;i++){
        arr2[i]=(arr[i-1]+arr[i]+arr[i+1])/3;
    }
    arr2[n-1]=(arr[n-2]+arr[n-1])/2;
    printf("%d",arr2[0]);
    for(int i=1;i<n;i++)
        printf(" %d",arr2[i]);
    return 0;
}