#include<iostream>
using namespace std;

void q_sort(int arr[],int low,int high){
    if(high<=low) return;
    int i=low;
    int j=high+1;
    int key=arr[low];
    while(true){
        while(arr[++i]<key){
            if(i==high) break;
        }
        while(arr[--j]>key){
            if(j==low)  break;
        }
        if(i>=j)    break;
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    int temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    q_sort(arr,low,j-1);
    q_sort(arr,j+1,high);
}

int main(){
    int a[]={57,68,59,52,72,28,96,33,24};
    q_sort(a,0,sizeof(a)/sizeof(a[0])-1);
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
        cout<<a[i]<<" ";
    }
    return 0;
}