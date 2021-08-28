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

ll pow2[N];

void binary();

int main() {
    freopen("main.inp","r",stdin);

    /*
    The keystone:
    How many answer are there having the same prefix you've processed
    (can be calculated using DP or combinatorics)
    */

    //Set up
    pow2[0] = 1ll;
    for (int i = 1; i <= 30; i++) pow2[i] = pow2[i - 1] << 1;

    binary();
}

void binary() {
    /*
    Given a list of all the binary numbers of length n sorted in lexicographic order.
    Answers the queries:
    1 s : Print out the s-th number in the list
    2 s : Determine the position of s in the list
    */

    /*
    Let's say We have built k first positions and We are considering the position t = k + 1
    The number's in this form: ddd.dddxx..xx
                          pos: 123...kt....n
    We have two options: place '1' or '2' on the t.
    Observation 1: How many numbers are there in the list that has the same first
    k digits and smaller than s (lexicographically, of course), no matter how we place digits in the remaining places?

    If we choose '0', the answer is 0. Because we placed '0' - the minimum number we can place,
    the order have to be decided by the left 'x'.

    If we choose '1', what would happen?
    Then any number with the same first k digits and '0' at t will smaller than the current
    number (according to the definition of lexicographical order.)
    Now, how many numbers are there?
    Look closer to the left digits. After placing the t digits, there are only n - t positions left.
    Since there are two options ('1' and '0') for each of them, the answer is 2^(n - t) (Simple combinatorics, isn't it?)
    */

    /*
    In this example, we have no limitation on numbers of digit
    There are some problems requires other constraints.
    */

    int n, q;   

    cin >> n >> q;

    while (q--) {
        int x; 
        cin >> x;

        if (x == 1) {
            int t;
            cin >> t;

            string res = "";

            for (int i = 1; i <= n; i++) {
                if (t <= pow2[n - i]) {
                    res = res + '0';
                } else {
                    t -= pow2[n - i];
                    res = res + '1';
                }
            }

            cout << res << endl;
        } else {
            string s;
            cin >> s;

            int res = 1;
            
            for (int i = 1; i <= n; i++) res += (s[i - 1] - '0') * pow2[n - i];

            cout << res << endl;
        }
    }
}