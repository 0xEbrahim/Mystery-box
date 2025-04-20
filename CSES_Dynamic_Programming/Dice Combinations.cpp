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
 
 
void done() {
    int n ;
    cin >> n ;
    vector<int>dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 0 ; i <= n ; i++){
        for(int j = 1 ; j <= 6 ; j++){
            if(i - j >= 0)
                dp[i] += dp[i - j];
            if(dp[i] >= MOD)
                dp[i] -= MOD;
        }
    }
    cout << dp[n];
}
 
signed main() {
    BRO();
    HIRO();
    int t;
    t = 1;
//    cin >> t;
    while (t--) {
        done();
    }
    return 0;
}
