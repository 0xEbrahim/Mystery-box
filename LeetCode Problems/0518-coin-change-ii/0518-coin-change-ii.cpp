class Solution {
public:
int dp[301][5001];
    int solve(int i , int cost , vector<int>&c){
        if(cost == 0) return 1;
        if(i == c.size()) return 0;
        int &ret = dp[i][cost];
        if(~ret) return ret;
        ret = solve(i + 1 , cost , c);
        if(cost >= c[i]){
            ret += solve(i , cost - c[i] , c);
        }
        return ret;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp , -1 , sizeof dp);
        return solve(0 , amount , coins);
    }
};