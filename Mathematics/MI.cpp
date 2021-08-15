#include <bits/stdc++.h>

#define ii pair<int,int>
#define ll long long

using namespace std;

const int N = 3e5;
const ll MOD = 1e9 + 7;

//Necessary function
ll mul(ll a, ll b){return (a%MOD)*(b%MOD)%MOD;}
ll add(ll a, ll b){return ((a+MOD)%MOD + (b+MOD)%MOD)%MOD;}
ll fpow(ll a, ll b){
    ll res=1;
    while (b){
        if (b & 1) res=mul(res,a);
        b>>=1;
        a=mul(a,a);
    }
    return res;
}
ll inv(ll a) {return fpow(a,MOD-2);}

int main(){
    //freopen("main.inp","r",stdin);

    /*
    Calculate MI of factorials
    inv(fact[i]%MOD) (calculate the factorial with modulo first then calc the inverse.)
    */

    vector<ll> factinv(N,0), fact(N,1);
    for (int i=1;i<N;i++) {
        fact[i]=mul(fact[i-1],i);
        factinv[i]=inv(fact[i]);

        if (i <= 10) cout<<fact[i]<<" ";
    }cout<<endl;

    assert(mul(fact[4],factinv[4]) == 1);
}
