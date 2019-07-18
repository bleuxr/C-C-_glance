#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,temp;
    double mid;
    int mid2;
    vector<int> l;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&temp);
        l.push_back(temp);
    }
    temp=l.size();
    if(temp%2==0){
        mid=(double)(l[temp/2-1]+l[temp/2])/2;
        mid2=(l[temp/2-1]+l[temp/2])/2;
        if(l[0]>l[temp-1]){
            if(mid==mid2)
                printf("%d %d %d",l[0],mid2,l[temp-1]);
            else
                printf("%d %.1f %d",l[0],mid,l[temp-1]);
        }else{
            if(mid==mid2)
                printf("%d %d %d",l[temp-1],mid2,l[0]);
            else
                printf("%d %.1f %d",l[temp-1],mid,l[0]);
        }    
    }else{
        mid2=l[temp/2];
        if(l[0]>l[temp-1]){
            printf("%d %d %d",l[0],mid2,l[temp-1]);
        }else{
            printf("%d %d %d",l[temp-1],mid2,l[0]);
        }        
    }
    return 0;
}