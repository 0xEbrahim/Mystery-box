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
    int n , k ;
    cin >> n >> k;
    vector<int>v(n);
    for(auto &it : v)
        cin >> it;
    vector<int>dp(k + 1,INT_MAX);
    dp[0] = 0;
   for(int i = 0 ; i <= k ; i++){
       for(int j = 0 ; j < n ; j++){
           if(i - v[j] >= 0)
               dp[i] = min(dp[i], dp[i - v[j]] + 1);
       }
   }
   if(dp[k] == INT_MAX)cout << -1;
   else cout << dp[k];
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
