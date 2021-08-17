#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define ii pair<int,int>
#define ll long long

using namespace std;

const int N = 3e5;
const ll MOD = 1e9 + 7;
const int iINF = 1e9;

int n,m;
vector<int> g[N];

vector<int> topo;

bool vsd[N];
void dfs(int u){
    vsd[u]=1;
    for (int v : g[u]) if (!vsd[v]) dfs(v);
    topo.pb(u);
}

void CountPath(int s){
    int d[N];

    memset(d,0,sizeof d); //number of paths from s to i

    int k=0;
    for (int i=0;i<=topo.size();i++) {
        if (topo[i]==s){
            k=i;
            break;
        }
    }
    
    d[s]=1;
    for (int i=k;i<topo.size();i++) {
        int u = topo[i];
        for (int v:g[u]) d[v]+=d[u];
    }
    cout<<"Number of paths: ";
    for (int i=1;i<=n;i++)cout<<d[i]<<" ";
    cout<<endl;
}

void LongestPath(){
    // Longest path on DAG
    int d[N]; //dp[i]: longest path starting from i

    for (int i=topo.size()-1;i>=0;i--){ // loop backwards
        int u=topo[i];
        int &res=d[u];
        
        res=0;
        for (int v : g[u]) res=max(res,d[v]+1);
    }
    cout<<"Longest path: ";for (int i=1;i<=n;i++) cout<<d[i]<<" ";
    cout<<endl;
}

int main(){
    freopen("main.inp","r",stdin);
    //Topological sorting
    
    cin>>n>>m;
    while (m--) {
        int u,v;cin>>u>>v;
        g[u].pb(v);
    }

    for (int i=1;i<=n;i++) if(!vsd[i]) dfs(i);
    reverse(topo.begin(),topo.end());
    for (int num:topo) cout<<num<<" ";cout<<endl;

    
    LongestPath();
    CountPath(1);


    return 0;
}
