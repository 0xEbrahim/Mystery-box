class Solution {
public:
int dp[10000 + 4];
int solve(int n){
    if(n == 0)
        return 0;
    if(n < 0)
        return INT_MAX;
    int &ret = dp[n];
    if(~ret)
        return ret;
    int op1 = INT_MAX;
    ret = INT_MAX;
    for(int i = 1 ; i <= 100 ; i++){
        if(i * i  > n)
            break;
        op1 = solve(n - i * i) + 1;
        ret = min(op1, ret);
    }
    return ret ;
}
int numSquares(int n) {
        memset(dp, -1 , sizeof dp);
        return solve(n);
    }
};
