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
    int n , x;
    cin >> n >> x;
    vector<int>price(n), pages(n);
    for(auto &it : price)
        cin >> it;
    for(auto &it : pages)
        cin >> it;
    vector<vector<int>>dp(2, vector<int>(x + 1, 0));
    for(int i = n - 1 ; ~i ; i--){
        int cur = i & 1;
        int next = (i + 1) & 1;
        for(int j = 0 ; j <= x ; j++){
            dp[cur][j] = dp[next][j];
            if(j - price[i] >= 0)
                dp[cur][j] = max(dp[cur][j], dp[next][j - price[i]] + pages[i]);
        }
    }
    cout << dp[0][x];
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
