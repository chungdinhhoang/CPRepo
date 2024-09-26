// lazy propagation with one-based indexing
//
// build:
//    lazySegtree<int> seg(n); // vector<int> a(n + 1)
//    seg.build(a); // vector `a` must be one-indexed
// 
// update:
//    seg.update(l, r, inc); //increase a[l -> r] += inc
//    //you may want to set this
// query:
//    seg.query(l, r)

template <class T>
struct lazySegTree {
  vector<T> st, lazy;
  int n;
  lazySegTree(int _n) : n(_n) {
    T default_value = 0;
    st.assign(4 * n + 5, default_value);
    lazy.assign(4 * n + 5, default_value);
  }  
  void build(const vector<T> &a) {
    build(a, 1, 1, n);
  }
  void build(const vector<T> &a, int id, int l, int r) {
    lazy[id] = 0;
    if(l == r) {
      if(l < a.size()) {
        st[id] = a[l];
      }
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 | 1]);
  }
  void down(int id) {
    if(lazy[id] == 0)
      return;
    st[id * 2] += lazy[id];
    st[id * 2 | 1] += lazy[id];
    lazy[id * 2] += lazy[id];
    lazy[id * 2 | 1] += lazy[id];
    lazy[id] = 0;
  }
  void update(int u, int v, T val) {
    update(u, v, val, 1, 1, n);
  }
  void update(int u, int v, T val, int id, int l, int r) {
    if(v < l || r < u) return;
    if(u <= l && r <= v) {
      lazy[id] += val;
      st[id] += val;
      return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(u, v, val, id * 2, l, mid);
    update(u, v, val, id * 2 | 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 | 1]);
  }
  T query(int u, int v) {
    return query(u, v, 1, 1, n);
  }
  T query(int u, int v, int id, int l, int r) {
    if(v < l || r < u) {
      return -INF;
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    down(id);
    return max(query(u, v, id * 2, l, mid), query(u, v, id * 2 | 1, mid + 1, r));
  }
};

