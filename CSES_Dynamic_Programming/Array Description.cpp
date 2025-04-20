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
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> dp(2, vector<int>(m + 2, 0));
    for(int i = 0 ; i <= m ; i++)
        dp[(n + 1) & 1][i] = 1;
    for(int i = n ; i >= 1 ; i--){
        for(int j = 0 ; j <= m ; j++){
            dp[i & 1][j] = 0;
            if(v[i] == 0){
                int mn = (j == 0) ? 1 : max(1LL, j - 1);
                int mx = (j == 0) ? m : min(m, j + 1);
                for(int k = mn ; k <= mx ; k++){
                    dp[i & 1][j] += dp[(i + 1) & 1][k];
                    dp[i & 1][j] %= MOD;
                }
            }else {
                if (j == 0 || abs(v[i] - j) <= 1) {
                    dp[i & 1][j] += dp[(i + 1) & 1][v[i]];
                    dp[i & 1][j] %= MOD;
                }
            }
        }
    }
    cout << dp[1][0];
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
