#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

#define endl '\n'

#define pb push_back

#define ll long long
#define ii pair<int,int>
#define r first
#define c second
#define x first
#define y second

const int N = 1e6 + 5;
const int iINF = 1e9;
const ll INF = 1e18;

struct edge {
    int u, v, cap, flow;
};

struct dinic {
public:
    int n, s, t;
    vector<int> d, ptr;
    // ptr: avoids revisit invalid nodes
    vector<edge> e;
    vector<vector<int> > g;
    // Remember: g stores indices of its edges in e (for quick modifications)

    dinic(int n): n(n), g(n + 1), ptr(n + 1), d(n + 1) {
        e.clear();
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
    }

    void add(int u, int v, int c) {
        edge a1 = {u, v, c, 0}, a2 = {v, u, 0, 0};

        g[u].push_back(int(e.size())); e.push_back(a1);
        g[v].push_back(int(e.size())); e.push_back(a2);
    }

    int maxflow(int _s, int _t) {
        s = _s, t = _t; 
        int flow = 0;

        while (true) {
            if (!bfs()) break;

            for (int i = 1; i <= n; i++) ptr[i] = 0;
            while (int pushed = dfs(s, iINF)) flow += pushed;
        }

        return flow;
    }

private:
    bool bfs() {
        for (int i = 1; i <= n; i++) d[i] = -1;
        d[s] = 0;

        queue<int> q;
        q.push(s);

        while (q.size() && d[t] == -1) {
            int u = q.front(); q.pop();

            for (int id : g[u]) {
                edge a = e[id];

                if (d[a.v] == -1 && a.cap > a.flow) {
                    d[a.v] = d[u] + 1;
                    q.push(a.v);
                }
            }
        }

        return d[t] != -1;
    }


    int dfs(int u, int flow) {
        if (flow == 0) return 0;
        if (u == t) return flow;

        for (; ptr[u] < g[u].size(); ptr[u]++) {
            int id = g[u][ptr[u]];
            edge a = e[id];

            if (d[a.v] != d[u] + 1) continue;
            if (int pushed = dfs(a.v, min(flow, a.cap - a.flow))) {
                if (pushed) {
                    e[id].flow += pushed;
                    e[id^1].flow -= pushed;
                    return pushed;
                }
            }
        }

        return 0;
    }
};

int n, m, s, t;

void solve() {
    cin >> n >> m >> s >> t;

    dinic mx(n);
    
    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        mx.add(a, b, c);
    }

    cout << mx.maxflow(s, t);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("main.inp","r",stdin);
    #endif

    int t = 1;
    //cin >> t;
    while (t--) solve();
}