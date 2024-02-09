class Solution {
public:
int dp[10000+15];
vector<int>co;

        int solve(int am){
            if(am == 0) return 0;
            int &ret = dp[am];
            if(~ret) return ret;
            ret = 100000;
            for(auto i : co){
                if(am >= i){
                    ret = min(ret , solve(am - i) + 1);
                }
            }
            return ret;
        }


    int coinChange(vector<int>& coins, int amount) {
        memset(dp , -1 , sizeof dp);
        for(int i = 0 ; i < coins.size() ; i++){
            co.push_back(coins[i]);
        }
        int ans = solve(amount);
        if(ans == 100000)
            ans = -1;
        return ans;
    }
};