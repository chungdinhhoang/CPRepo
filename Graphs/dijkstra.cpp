struct dijkstra {
	int n;
	vector<vector<pair<int, long long>> > g;
	int s;
	vector<long long> dist;

	dijkstra(int n): n(n) {
		g.assign(n + 1, vector<pair<int, long long> >());
		dist.assign(n + 1, 1e18);
	}

	void add_edge(int u, int v, ll c) {
		// change this whether directed or not
		g[u].push_back(make_pair(v,c));
		g[v].push_back(make_pair(u,c));
	}

	void build() {
		set<pair<long long, int> > st;

		st.insert(make_pair(0, s)); dist[s] = 0;

		while (st.size()) {
			long long du = st.begin()->fi; int u = st.begin()->se;
			st.erase(st.begin());
			if (du != dist[u]) continue;

			for (auto &[v, c] : g[u]) {
				if (dist[v] > dist[u] + c) {
					dist[v] = dist[u] + c;
					st.insert(make_pair(dist[v], v));
				}
			}
		}
	}
};
