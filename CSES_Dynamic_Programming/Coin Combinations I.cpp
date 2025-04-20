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
 
int n , x;
vector<int>v;
int dp[1000000 + 2];
void done() {
cin >> n >> x;
v.assign(n, 0);
for(auto &it : v)
    cin >> it;
dp[0] = 1;
// go(x) => go(x - a[i])
for(int i = 0 ; i <= x ; i++){
    for(int j = 0 ; j < n ; j++){
        if(i - v[j] >= 0)
            dp[i] += dp[i - v[j]];
        if(dp[i] >= MOD)
            dp[i] -= MOD;
    }
}
cout << dp[x] << endl;
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
