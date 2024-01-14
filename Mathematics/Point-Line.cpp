#include <bits/stdc++.h>

using namespace std;

#define gcd(x, y) __gcd(x, y)
#define ll long long
#define ii pair<int, int>

const int N = 5e5 + 5;
const ll MOD = 1e9 + 7;
const int iINF = 1e9;

#define pt pair<long long, long long>
#define x first
#define y second

struct Line {
    pt a, ab;

    Line(pt _a, pt _ab): a(_a), ab(_ab) {}
};

pt operator - (const pt& a, const pt& b) {return make_pair(a.x - b.x, a.y - b.y);}

ll operator * (const pt& a, const pt& b) {return a.x*b.x + a.y*b.y;}
ll operator ^ (const pt& a, const pt& b) {return a.x*b.y - a.y*b.x;}

pt refine(pt a) { // only for pt = pair<ll, ll>
    ll g = gcd(a.x, a.y);
    if (!g) return a;

    if (g < 0) g = -g;
    a.x /= g, a.y /= g;
    return a;
}

int dir(pt a, pt b, pt c) {
    ll x = (b - a) ^ (c - a);

    if (x == 0) return 0;
    else if (x > 0) return 1;
    else return 2;
}

int main() {
    #ifdef CHUNGDINH
    freopen("main.inp", "r", stdin);
    //freopen("main.out", "w", stdout);
    #endif // CHUNGDINH
}
