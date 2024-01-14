/* 
 * Caution:
 *   * need to cast into int before printing
 * source: Benq
*/
struct Mint {
  int v;
  explicit operator int() const { return v; }
  Mint() { v = 0; }
  Mint(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
Mint &operator+=(Mint &a, Mint b) {
  if ((a.v += b.v) >= MOD) a.v -= MOD;
  return a;
}
Mint &operator-=(Mint &a, Mint b) {
  if ((a.v -= b.v) < 0) a.v += MOD;
  return a;
}
Mint operator+(Mint a, Mint b) { return a += b; }
Mint operator-(Mint a, Mint b) { return a -= b; }
Mint operator*(Mint a, Mint b) { return Mint((long long)a.v * b.v); }
Mint &operator*=(Mint &a, Mint b) { return a = a * b; }
Mint pow(Mint a, long long p) {
  assert(p >= 0);
  return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
Mint inv(Mint a) {
  assert(a.v != 0);
  return pow(a, MOD - 2);
}
Mint operator/(Mint a, Mint b) { return a * inv(b); }
