int n, m;
vector<int> g[N];

int tin[N], low[N];
int dfsTime = 0;

bool articulation_point[N];
int bridge_count = 0;


void dfs(int u, int pre = -1) {
    tin[u] = low[u] = ++dfsTime;
    int child = 0;

    for (int v : g[u]) {
        if (v == pre) continue;
        if (tin[v]) low[u] = min(low[u], tin[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            child++;

            if (low[v] > tin[u]) bridge_count++;
            if (low[v] >= tin[u] && pre != -1) articulation_point[u] = true;
        }
    }

    if (pre == -1 && child >= 2) articulation_point[u] = true;
}