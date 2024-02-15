const int N = (int) 2e5 + 5, LG = 18;

template<class T>
struct RMQ {
  T st[LG + 1][N];
  int n;
  void build (const vector<T> &a) {
    n = a.size() - 1;
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= LG; ++j)
      for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
  }
  T queryMin(int l, int r) {
    int k = __lg(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
  }
  T queryMax(int l, int r) {
    int k = __lg(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
  }
};
