int n,m,s,t;  
vector<ii> g[N];

void add(int u, int v,int w){
    g[u].pb({v,w});
    g[v].pb({u,0});
}
int bfs(int s, int t, int p[N]){
    for (int i=1;i<=n;i++)p[i]=-1;p[s]=-2;

    queue<ii> q;
    q.push({iINF,s});

    while (!q.empty()){
        int u=q.front().second;
        int flow = q.front().first;
        q.pop();

        for (ii a : g[u]){
            int v = a.first,w = a.second;

            if (w > 0 && p[v] == -1){
                p[v]=u;
                int new_flow = min(flow,w);

                if (v == t) return new_flow;

                q.push({new_flow,v});
            }
        }
    }

    return 0;
}
int max_flow(int s, int t){
    int p[N];

    int max_flow=0;

    int flow;
    while (flow = bfs(s,t,p)){
        for (int v = t; v != s; v = p[v]){
            int u = p[v];
            //g[u][v].second -= flow;
            for (ii &a : g[u]) if (a.fi == v) a.se -= flow;
            //g[v][u].second += flow;
            for (ii &a : g[v]) if (a.fi == u) a.se += flow;
        }

        max_flow += flow;
    }
    return max_flow;
}

/* 
Remember: 

After getting the max flow, the graph had been changed 
and cannot be used anymore (Consider make a copy of it.)

You are using Adjacent List. Loop through all the edges 
and adjust it.(Rather than naively using indexes)
*/