#include<iostream>
#include<vector>
// #include<time.h>
using namespace std;

int main(){
    // clock_t start,end;
    // start=clock();
    int m,l,r,temp,count;
    long long sum;
    vector<int> k;
    vector<int> a;
    scanf("%d%d%d",&m,&l,&r);
    for(int i=0;i<m;i++){
        scanf("%d",&temp);
        k.push_back(temp);
    }
    a.push_back(1);
    for(int i=1;i<=r;i++){
        sum=0;
        if(m<i)
            count=m;
        else
            count=i;

        int ii=i-1;
        for(int j=0;j<count;j++){
            sum+=((long long)k[j]*(long long)a[ii]);
            sum%=998244353;
            ii--;
        }
        a.push_back(sum);
    }
    for(int i=l;i<=r;i++){
        printf("%d\n",a[i]);
    }
    // end=clock();
    // printf("time=%f\n", (double)(end - start) / CLOCKS_PER_SEC);//1
    return 0;
}