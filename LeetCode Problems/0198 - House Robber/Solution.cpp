class Solution {
public:
    int dp[100 + 12];
    int solve(int i , vector<int>&v){
        if(i >= v.size())
            return 0;
        int &ret = dp[i];
        if(~ret)
            return ret;
        int op1= solve(i + 1 , v);
        int op2 = solve(i + 2 , v) + v[i];
    return ret = max(op1, op2);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1 , sizeof dp);
        return solve(0,nums);
    }
};
