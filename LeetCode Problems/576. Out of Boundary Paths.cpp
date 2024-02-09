typedef long long ll;
class Solution {
public:
ll mod = 1e9 + 7;
    ll dx[4] = {1, -1, 0, 0},
    dy[4] = {0, 0, 1, -1};
ll dp[55][55][55];
ll solve(ll i , ll j , ll mx, ll  n , ll m){
    if(i < 0 || i >= n || j < 0 || j >= m)
        return 1;
    if(mx <= 0)
        return 0;
    ll &ret = dp[i][j][mx];
    if(~ret)
        return ret%mod;
    ll op1 = 0;
    for(ll k = 0 ; k < 4 ; k++){
        op1 += solve(i + dx[k], j + dy[k], mx - 1 , n , m);
    }
    return ret = op1%mod;
}
ll findPaths(ll n, int m, int maxMove, int startRow, int startColumn) {
    memset(dp, -1 , sizeof dp);
    return solve(startRow, startColumn, maxMove, n , m);
}
};
