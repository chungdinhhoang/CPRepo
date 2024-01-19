#define ll long long
#define ii pair<long long, long long>
#define fi first
#define se second
#define MP make_pair
#define sz(x) (long long)(x.size())
#define all(x) x.begin(), x.end()
#define mmax(a, b) a = max(a, b)
#define mmin(a, b) a = min(a, b)
#define For(i,l,r) for (long long i = (l); i <= (r); i++)
#define Ford(i,r,l) for (long long i = (r); i >= (l); i--)

const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int iINF = 1e9;

/*
Check before submitting:
+ corner cases (n=1,n=0,full of 1,full of 0,)
+ use fastio
+ check input output type (stdin or file)
+ Array bounds ( segmentation fault)
+ int or long long
+ reset all the variables (multiple tests)
+ is the graph connected (may have > 1 connected components)
+ reindex the string => s = "#" + s;
+ use 1ll << x, not 1 << x
+ while using board, be careful with m and n
*/