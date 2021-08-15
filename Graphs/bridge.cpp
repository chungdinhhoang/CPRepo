#include <bits/stdc++.h>

#define ii pair<int,int>

using namespace std;

const int N = 3e5;

int n,m;
vector<int> g[N];

int tin[N], low[N];
int dfsTime=0;

void dfs(int u, int pre);

int main(){
    freopen("main.inp","r",stdin);
    memset(tin,0,sizeof tin);

    //Find bridges and articulation points

    // initialize the graph
    cin >> n >> m;
    while (m--) {
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int u=1;u<=n;u++){
        if (!tin[u]) dfs(u,-1);
    }
}

void is_bridge(int u,int v){
    printf("%d - %d.\n",u,v);
}

void is_articulation_point(int u){
    printf("%d is an articulation point.\n",u);
}

void dfs(int u, int pre){
    tin[u]=low[u]=++dfsTime;
    int child=0; // just used for the root of the dfs tree

    for(int v : g[u]){
        if (v == pre) continue;

        if (!tin[v]){
           // cout<<v<<endl;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            child++;

            if (low[v] > tin[u]) is_bridge(u,v);
            if (low[v] >= tin[u] && pre != -1) is_articulation_point(u); // pre != -1 is an important condition.
        } else low[u]=min(low[u],tin[v]);
    }

    if (pre == -1 && child >= 2) is_articulation_point(u); //corner case
}