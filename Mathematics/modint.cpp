/* 
 * Caution:
 *   *need to cast into an int before printing
 * source: Benq
*/
struct modint {
  int v;
  explicit operator int() const { return v; }
  modint() { v = 0; }
  modint(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
modint &operator+=(modint &a, modint b) {
  if ((a.v += b.v) >= MOD) a.v -= MOD;
  return a;
}
modint &operator-=(modint &a, modint b) {
  if ((a.v -= b.v) < 0) a.v += MOD;
  return a;
}
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return modint((long long)a.v * b.v); }
modint &operator*=(modint &a, modint b) { return a = a * b; }
modint pow(modint a, long long p) {
  assert(p >= 0);
  return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
modint inv(modint a) {
  assert(a.v != 0);
  return pow(a, MOD - 2);
}
modint operator/(modint a, modint b) { return a * inv(b); }
