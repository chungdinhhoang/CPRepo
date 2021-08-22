#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <random>
#include <queue>

#define endl "\n"

#define pb push_back
#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define fi first
#define se second

#define all(x) x.begin(),x.end()

#define EPS (double)1e-6
#define INF (long long)(1e18)

using namespace std;

const ll MOD = 1e9 + 7;
const int N = 5e2+5;
const int iINF = 1e9+7;
const double oo = 1e12; 

int n;
int a[N];

ll SpT[N][25];

//summation on array
ll get(int l, int r);
void sum();

//Sparse Table on Tree  
int p[N]; // p[i]: parents of node i.
int d[N]; // d[i]: depth of node i. Calculated by a DFS
void tree();

int main(){
    //srand(time(0));

    #ifndef ONLINE_JUDGE
    freopen("main.inp","r",stdin);
    #endif

    tree();

    return 0;
}

void sum() {
    memset(SpT, -1, sizeof SpT);
    // works similarly with GCD, XOR, MIN(MAX),...
    // O(nlogn) preprocess

    /*
    Only works in O(1) with overlap-allowed operations.
    Ex: Bitwise Operation, Minimum(Maximum), GCD,...
    */

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int k = 0; k <= 20; k++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            if (!k) SpT[i][k]=a[i];
            else SpT[i][k] = SpT[i][k-1] + SpT[i + (1 << (k - 1))][k - 1];
        }
    }

    for (int i=1;i<=n;i++) {
        for (int j = 0; j <= 20 && SpT[i][j] != -1; j++) cout << SpT[i][j] << " ";
        cout << endl;
    } 

    cout << get(5,5);
}
ll get(int l, int r) {
    int s=r - l + 1;

    ll res = 0;

    int i=0;
    while (i <= s) {
        if (s & (1 << i)) {
            res += SpT[l][i];
            l += 1 << i;
        }
        i++;
    }

    return res;
}

void tree() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];

    p[1] = -1;
    for (int k = 0; k <= 20; k++) {
        for (int i = 1; i <= n; i++) {
            if (k == 0) SpT[i][k] = p[i];
            else {
                if (SpT[i][k - 1] != - 1) SpT[i][k] = SpT[SpT[i][k - 1]][k - 1];
                else SpT[i][k] = -1;
            }
        }
    }

    for (int i = 1;i <= n; i++) {
        cout << i << ": ";
        for (int j = 0; j <= 20; j++) {
            if (SpT[i][j] == -1) break;
            cout << SpT[i][j] << " ";
        } 
        cout << endl;
    }

    //I will implememt LCA soon =))
}