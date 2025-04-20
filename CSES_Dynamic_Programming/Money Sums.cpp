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
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &it : v)
        cin >> it;
    int total = accumulate(all(v), 0LL);
    vector<vector<bool>>dp(2, vector<bool>(total + 1, false));
    dp[n & 1][0] = true;
    for(int i = n - 1; ~i ; i--){
        for(int j = 0 ; j <= total ; j++){
            dp[i & 1][j] = (dp[i & 1][j] | dp[(i + 1) & 1][j]);
            if(j - v[i] >= 0)
                dp[i & 1][j] = (dp[i & 1][j] | dp[(i + 1) & 1][j - v[i]]);
        }
    }
    vector<int>ans;
    for(int i = 1 ; i <= total ; i++)
        if(dp[0][i])
            ans.push_back(i);
    cout << ans.size() << endl;
    for(auto &it : ans)
        cout << it << " ";
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
