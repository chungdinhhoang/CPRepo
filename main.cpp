#include <bits/stdc++.h>

#define ll long long
#define ii pair<long long, long long>
#define fi first
#define se second
#define MP make_pair

using namespace std;

const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int iINF = 1e9;

int n;
ll a[100];

ll get(int i, ll s1, ll s2) {
    if (i == n) return abs(s1 - s2);
    return min(get(i + 1, s1 + a[i], s2), get(i + 1, s1, s2 + a[i]));
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << get(0, 0, 0);
}

int main(){
    #ifdef CHUNGDINH
    freopen("main.inp", "r", stdin);
    #endif // CHUNGDINH

    cout << fixed << setprecision(8);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}


/*
Check before submitting:
+ Array bounds ( segmentation fault)
+ int or long long
+ reset all the variables (multiple tests)
+ is the graph connected (may have > 1 connected components)
*/
