#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXV=501;
const int INF=1000000000;

int n,m,c1,c2;
int G[MAXV][MAXV],cost[MAXV][MAXV];
int d[MAXV],minCost=INF;
bool vis[MAXV]={false};
vector<int> pre[MAXV];
vector<int> tempPath,path;

void dijkstra(int s){
    fill(d,d+MAXV,INF);
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,min=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<min){
                u=j;
                min=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int v=0;v<n;v++){
            if(vis[v]==false&&G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){
                    d[v]=d[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u]+G[u][v]==d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void dfs(int v){
    if(v==c1){
        tempPath.push_back(v);
        int tempCost=0;
        for(int i=tempPath.size()-1;i>0;i--){
            int id=tempPath[i],idNext=tempPath[i-1];
            tempCost+=cost[id][idNext];
        }
        if(tempCost<minCost){
            minCost=tempCost;
            path=tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i=0;i<pre[v].size();i++){
        dfs(pre[v][i]);
    }
    tempPath.pop_back();
}

int main(){
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    int u,v;
    fill(G[0],G[0]+MAXV*MAXV,INF);
    fill(cost[0],cost[0]+MAXV*MAXV,INF);
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        scanf("%d%d",&G[u][v],&cost[u][v]);
        G[v][u]=G[u][v];
        cost[v][u]=cost[u][v];
    }
    dijkstra(c1);
    dfs(c2);
    for(int i=path.size()-1;i>=0;i--){
        printf("%d ",path[i]);
    }
    printf("%d %d\n",d[c2],minCost);
    return 0;
}