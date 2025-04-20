#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define endl '\n'
#define all(v) ((v).begin()), ((v).end())
void BRO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
const int mod = 998244353;
const int MOD = 1e9 + 7;
template <typename T> void stop(T x){return void(cout << x << endl);}
void HIRO(void) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Personal\\No\\CP\\input.txt", "r", stdin);
    freopen("D:\\Personal\\No\\CP\\output.txt", "w", stdout);
#endif
}
 
struct mint {
    int value;
    mint(int v = 0) { value = v % MOD; if(value < 0) value += MOD; }
    mint(int a, int b) : value(0) { *this += a; *this /= b; }
 
    mint& operator+=(mint const& b) { value += b.value; if(value >= MOD) value -= MOD; return *this; }
    mint& operator-=(mint const& b) { value -= b.value; if(value < 0) value += MOD; return *this; }
    mint& operator*=(mint const& b) { value = 1ll * value * b.value % MOD; return *this; }
 
    friend mint power(mint a, long long e) {
        mint res = 1; while(e) { if(e & 1) res *= a; a *= a; e >>= 1; }
        return res;
    }
    friend mint inv(mint a) { return power(a, MOD - 2); }
 
    mint &operator/=(mint const& b) { return *this *= inv(b); }
    friend mint operator+(mint a, mint const b) { return a += b; }
    friend mint operator-(mint a, mint const b) { return a -= b; }
    friend mint operator-(mint const a) { return 0 - a; }
    friend mint operator*(mint a, mint const b) { return a *= b; }
    friend mint operator/(mint a, mint const b) { return a /= b; }
    friend ostream& operator<<(ostream& os, mint const& a) { return os << a.value; }
    friend bool operator==(mint const &a, mint const& b) { return a.value == b.value; }
    friend bool operator!=(mint const& a, mint const& b) { return a.value != b.value; }
};
 
void done() {
    int n ;
    cin >> n ;
    mint dp[2][2] = {};
    dp[n & 1][0] = dp[n & 1][1] = 1;
    for(int i = n - 1 ; ~i ; i--){
        dp[i & 1][0] = 2 * dp[(i + 1) & 1][0] + dp[(i + 1) & 1][1];
        dp[i & 1][1] = 4 * dp[(i + 1) & 1][1] + dp[(i + 1) & 1][0];
    }
    cout << dp[1][1] + dp[1][0] << endl;
}
 
 
signed main() {
    BRO();
    HIRO();
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        done();
    }
    return 0;
}
