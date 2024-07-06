/**
 * Description: Finding the diameter of tree in O(V + E)
 */

struct TD {
  int ans = 0;
  vector<vector<int>> g;

  int Dfs (int u, int pr) {
    pi lol = {0, 0};
    for (int v : g[u]) {
      if (v == pr) continue;
      int te = Dfs(v, u);
      if (lol.ff < te) {
        lol.ss = lol.ff;
        lol.ff = te;
      } else if (lol.ss < te) {
        lol.ss = te;
      }
    }
    ans = max(ans, lol.ff + lol.ss);
    return lol.ff + 1;
  }

  int run() {
    Dfs(1, 1);
    return ans;
  }

  TD(vector<vector<int>>& _g) : g(_g) {}
};
