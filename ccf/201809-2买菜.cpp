#include<iostream>
using namespace std;

int main(){
    int n,sum;
    int arr1[2001][2];
    int arr2[2001][2];
    sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&arr1[i][0],&arr1[i][1]);
    }
    for(int i=0;i<n;i++){
        scanf("%d%d",&arr2[i][0],&arr2[i][1]);
    }
    int index1=0,index2=0;
    while(index1<=n&&index2<=n){
        if(arr1[index1][0]<=arr2[index2][0]){
            if(arr1[index1][1]<=arr2[index2][0])
                index1++;
            else if(arr1[index1][1]<=arr2[index2][1]){
                sum+=(arr1[index1][1]-arr2[index2][0]);
                index1++;
            }else{
                sum+=(arr2[index2][1]-arr2[index2][0]);
                index2++;
            }
        }else{
            if(arr2[index2][1]<=arr1[index1][0])
                index2++;
            else if(arr2[index2][1]<=arr1[index1][1]){
                sum+=(arr2[index2][1]-arr1[index1][0]);
                index2++;
            }else{
                sum+=(arr1[index1][1]-arr1[index1][0]);
                index1++;
            }
        }
    }
    printf("%d",sum);
    return 0;
}