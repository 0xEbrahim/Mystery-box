class Solution {
public:
int dp[50];
    int solve(int i){
        if(i == 0)
            return 0;
        if(i == 1)
            return 1;
        int &ret = dp[i];
        if(~ret)
            return ret;
        return ret = solve(i - 1) + solve(i - 2);
    }
    int fib(int n) {
        memset(dp, -1, sizeof dp);
        dp[0] = 0;
        dp[1] = 1;
        solve(n);
        return dp[n];
    }
};