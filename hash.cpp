const ll mod = 1e9 + 7;
const ll mod1 = 1e9 + 9;
const int kek = 228233;

struct myhash {
    vector <ll> h, h1;
    myhash (string s) {
        int n = s.size();
        h.resize(n);
        h1.resize(n);
        h[0] = s[0] - '0' + 1;
        h1[0] = s[0] - '0' + 1;
        for (int i = 1; i < n; i++) {
            h[i] = (1ll * h[i - 1] * kek) % mod;
            h[i] = (h[i] + s[i] - '0' + 1) % mod;
            h1[i] = (1ll * h1[i - 1] * kek) % mod1;
            h1[i] = (h1[i] + s[i] - '0' + 1) % mod1;
        }
    }
    pair <ll, ll> calc(int l, int r) {
        int len = r - l + 1;
        ll res = h[r];
        if (l) res -= (1ll * h[l - 1] * pw[len]) % mod;
        res = (res + mod) % mod;
        ll res1 = h1[r];
        if (l) res1 -= (1ll * h1[l - 1] * pw[len]) % mod1;
        res1 = (res1 + mod1) % mod1;
        return {res, res1};
    }
    myhash () {}
};
