#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXV=501;
const int INF=1000000000;

int n,m,c1,c2;
int weight[MAXV];
int G[MAXV][MAXV];
int num[MAXV],w[MAXV],d[MAXV];
int vis[MAXV]={false};

void dijkstra(int s){
    fill(d,d+MAXV,INF);
    d[s]=0;
    num[s]=1;
    w[s]=weight[s];
    for(int j=0;j<n;j++){
        int v=-1,min=INF;
        for(int i=0;i<n;i++){
            if(vis[i]==false&&d[i]<min){
                v=i;
                min=d[i];
            }
        }
        vis[v]=true;
        for(int i=0;i<n;i++){
            if(vis[i]==false&&G[v][i]!=INF){
                if(d[v]+G[v][i]<d[i]){
                    d[i]=d[v]+G[v][i];
                    w[i]=weight[i]+w[v];
                    num[i]=num[v];
                }else if(d[v]+G[v][i]==d[i]){
                    num[i]+=num[v];
                    if(weight[i]+w[v]>w[i]){
                        w[i]=weight[i]+w[v];
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    for(int i=0;i<n;i++){
        scanf("%d",&weight[i]);
    }
    fill(G[0],G[0]+MAXV*MAXV,INF);
    int r1,r2;
    for(int i=0;i<m;i++){
        scanf("%d%d",&r1,&r2);
        scanf("%d",&G[r1][r2]);
        G[r2][r1]=G[r1][r2];
    }
    dijkstra(c1);
    printf("%d %d",num[c2],w[c2]);
    return 0;
}