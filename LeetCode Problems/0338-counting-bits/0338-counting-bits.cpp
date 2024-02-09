class Solution {
public:
    int dp[100000 + 10];
    int solve(int n){
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        int &ret = dp[n];
        if(~ret)
            return ret;
        if(n%2 == 0)
            return ret = solve(n/2);
        else return ret = 1 + solve(n/2);
    }
    vector<int> countBits(int n) {
        vector<int>ans(n + 1);
        memset(dp,-1,sizeof dp);
        for(int i = 0 ; i <= n ; i++)
            ans[i] = solve(i);
        return ans;
    }
};