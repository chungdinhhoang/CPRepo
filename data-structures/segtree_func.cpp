template<class T, int SZ>
struct segTree {
  vector<T> st;
  function<T(T,T)> F;

  segTree(function<T(T,T)> _F) {
    T default_value = 0;
    F = _F;
    st.assign(4 * SZ, default_value);
  }
  void build(const vector<T>& a, int id = 1, int l = 1, int r = SZ) {
    if(l == r) {
      if(l < a.size()) {
        st[id] = a[l];
      }
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = F(st[id * 2],st[id * 2 | 1]);
  }
  void update(int pos, T val, int id = 1, int l = 1, int r = SZ) {
    if(l == r) {
      st[id] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(pos, val, id * 2, l, mid);
    else update(pos, val, id * 2 | 1, mid + 1, r);
    st[id] = F(st[id * 2],st[id * 2 | 1]);
  }
  T query(int u, int v, int id = 1, int l = 1, int r = SZ) {
    if(u == l && r == v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    if (v <= mid) return query(u, v, id * 2, l, mid);
    else if (u >= mid + 1) return query(u, v, id * 2 | 1, mid + 1, r);
    else return F(query(u, mid, id * 2, l, mid),query(mid + 1, v, id * 2 | 1, mid + 1, r));
  }
};
