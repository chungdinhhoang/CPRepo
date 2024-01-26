struct hashing {
    //create MOD outside
    long long base = 311;
    int n;
    vector<long long> hs;
    vector<long long> invbase;

    hashing(string s) {
        n = s.size();
        hs.assign(n, 0); invbase.assign(n, 0);
        long long iv = inv(base);

        hs[0] = s[0]; invbase[0] = 1;
        long long p = 1;
        for (int i = 1; i < n; i++) {
            p = mul(p, base);
            hs[i] = add(hs[i - 1], mul(s[i], p));
            invbase[i] = mul(invbase[i - 1], iv);
        }
    }

    ll get(ll l, ll r) {
        ll res = hs[r];
        if (l) {
            res = add(res, -hs[l - 1]);
            res = mul(res, invbase[l]);
        }
        return res;
    }
};
