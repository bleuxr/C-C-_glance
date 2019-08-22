#include<cstdio>
#include<vector>
using namespace std;
const int maxn=100;
int maxdepth=1;

vector<int> t[100];
int flag[100]={0};
void dfs(int no,int depth){
    if(t[no].size()==0){
        flag[depth]++;
        if(depth>maxdepth){
            maxdepth=depth;
        }
        return;
    }
    for(int i=0;i<t[no].size();i++){
        dfs(t[no][i],depth+1);
    }
}

int main(){
    int n,m;
    int id,k,node;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&id,&k);
        for(int j=0;j<k;j++){
            scanf("%d",&node);
            t[id].push_back(node);
        }
    }
    dfs(1,1);
    for(int i=1;i<=maxdepth;i++){
        if(i!=1) printf(" ");
        printf("%d",flag[i]);
    }
    return 0;
}