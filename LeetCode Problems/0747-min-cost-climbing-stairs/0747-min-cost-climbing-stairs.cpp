class Solution {
public:
    int dp[1000 + 10];
    int solve(int i , int n, vector<int>&v){
        if(i >= n)
            return 0;
        int &ret = dp[i];
        if(~ret)
            return ret;
        int op1 , op2;
        op1 = solve(i + 1 , n , v) + v[i];
        op2 = solve(i + 2 , n , v) + v[i];
        return ret = min(op1 , op2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp , -1 , sizeof dp);
        return min(solve(0 , cost.size() , cost) , solve(1 , cost.size() , cost));        
    }
};