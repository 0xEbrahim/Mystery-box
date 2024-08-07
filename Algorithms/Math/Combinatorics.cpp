// make sure a & b < mod
int add(int a, int b, int mod) {
    ll res = (ll) a + b;
    if (res >= mod) res -= mod;
    if (res < 0) res += mod;
    return res;
}

int mul(int a, int b, int mod) {
    return (1LL * a * b) % mod;
}

int power(int a, int b, int mod) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = 1ll * ret * a % mod;
        a = 1ll * a * a % mod, b >>= 1;
    }
    return ret;
}

int inverse(int b, int mod) {
    return power(b, mod - 2, mod);
}

struct Comb {
    int mod;
    vector<int> fact; // pre process fact inv too :)
    Comb(int n, int m) {
        mod = m;
        fact.assign(n + 5, 1);
        for (int i = 1; i <= n; ++i) fact[i] = mul(i, fact[i - 1], mod);
    }

    int nPr(int n, int r) {
        return n < r ? 0 : mul(fact[n], inverse(fact[n - r], mod), mod);
    }

    int nCr(int n, int r) {
        return mul(nPr(n, r), inverse(fact[r], mod), mod);
    }
};
