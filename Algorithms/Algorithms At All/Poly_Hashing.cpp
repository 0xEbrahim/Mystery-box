mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r){
    return uniform_int_distribution<long long>(l, r)(rng);
}
struct Shash {
    int base, inv, mod, n;
    vector<long long>pw{1}, invpw{1}, pref{0};

    Shash(const string &s, int m, int b){
        mod = m;
        base=b;
        n=s.size();
        inv = 1;
        long long e = mod - 2;
        long long cur = base;

        while(e){
            if(e & 1)inv = 1ll * inv * cur % mod;
            (cur *= cur) %= mod;
            e >>= 1;
        }

        for(int i = 0 ; i < n ; i++){
            pw.push_back(pw.back() * base % mod);
            invpw.push_back(invpw.back() * inv % mod);
            pref.push_back((pref.back() + s[i] * pw[i]) % mod);
        }
    }

    long long get(long long l, long long r){
        return (pref[r + 1] - pref[l] + mod) * invpw[l] % mod;
    }
};
