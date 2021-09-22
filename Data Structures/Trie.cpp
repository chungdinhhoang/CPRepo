#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <cassert>

using namespace std;

#define endl '\n'

#define pb push_back

#define ll long long
#define ii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define x first
#define y second

const int N = 3e5 + 5;
const int iINF = 1e9;
const ll MOD = 1337377;
const ll MOD2 = 998244353;
const ll INF = 1e18;

struct trie {
    int end;
    int sz;
    int link[26];

    trie() {
        end = sz = 0;
        for (int i = 0; i < 26; i++) link[i] = -1;
    }
};

// 0 is the root

trie T[10 * N];
int num = 0;

void add(string s) {
    int u = 0;

    for (char c : s) {
        if (T[u].link[c - 'a'] == -1) T[u].link[c - 'a'] = ++num;
        u = T[u].link[c - 'a'];
        T[u].sz++;
    }

    T[0].sz++;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("main.inp","r",stdin);
   // freopen("main.out","w",stdout);
    #endif
}

/*
Array bounds *
long long vs int
Sometimes, VNOI views "arrays out of bounds" as "wrong answer"
*/
