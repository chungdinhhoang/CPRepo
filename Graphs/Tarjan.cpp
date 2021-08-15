#include <bits/stdc++.h>

#define ii pair<int,int>

using namespace std;

const int N = 3e5;

//SCC: Strong Connected Component

int n,m;
vector<int> g[N];

bool onStack[N];
stack<int> st;
int tin[N], low[N];
int dfsTime=0;

int SCCCount=0;

void dfs(int u);

int main(){
    freopen("main.inp","r",stdin);
    memset(tin,0,sizeof tin);
    memset(onStack,false,sizeof onStack);

    //Find bridges and articulation points

    // initialize the graph
    cin >> n >> m;
    while (m--) {
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }

    for (int u=1;u<=n;u++){
        if (!tin[u]) dfs(u);
    }

    cout<<SCCCount;
}

void dfs(int u) {
    onStack[u]=true;st.push(u);
    low[u]=tin[u]=++dfsTime;

    for(int v : g[u]){
       // cout<<u<<" -> "<<v<<endl;
        if (!tin[v]) dfs(v);
        if (onStack[v]) low[u]=min(low[u],low[v]); // low[v] not tin[v]
    }

    if (low[u]==tin[u]){ // new SCC found
        while (!st.empty()){
            int a = st.top();
            onStack[a]=false;st.pop();
            printf("%d ",a);
            if (a == u){
                printf("\n");
                break;
            }
        }
        SCCCount++;
    }
}