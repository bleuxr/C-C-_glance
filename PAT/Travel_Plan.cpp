#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXV=501;
const int INF=1000000000;
int n,m,c1,c2;
int d[MAXV],c[MAXV],pre[MAXV];
int G[MAXV][MAXV],cost[MAXV][MAXV];
bool vis[MAXV]={false};

void dijkstra(int s){
    fill(d,d+MAXV,INF);
    fill(c,c+MAXV,INF);
    d[s]=0,c[s]=0;
    pre[s]=s;
    for(int k=0;k<n;k++){
        int v=-1,min=INF;
        for(int i=0;i<n;i++){
            if(vis[i]==false&&d[i]<min){
                v=i;
                min=d[i];
            }
        }
        if(v==-1) return;
        vis[v]=true;
        for(int i=0;i<n;i++){
            if(vis[i]==false&&G[v][i]!=INF){
                if(d[v]+G[v][i]<d[i]){
                    d[i]=d[v]+G[v][i];
                    c[i]=c[v]+cost[v][i];
                    pre[i]=v;
                }else if(d[v]+G[v][i]==d[i]&&c[v]+cost[v][i]<c[i]){
                    c[i]=c[v]+cost[v][i];
                    pre[i]=v;
                }
            }
        }
    }
}

void dfs(int s){
    if(pre[s]==s){
        printf("%d ",s);
        return;
    }
    dfs(pre[s]);
    printf("%d ",s);
    return;
}

int main(){
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    fill(G[0],G[0]+MAXV*MAXV,INF);
    // fill(cost[0],cost[0]+MAXV*MAXV,INF);
    int u,v;
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        scanf("%d%d",&G[u][v],&cost[u][v]);
        G[v][u]=G[u][v];
        cost[v][u]=cost[u][v];
    }
    dijkstra(c1);
    dfs(c2);
    printf("%d %d",d[c2],c[c2]);
    return 0;
}