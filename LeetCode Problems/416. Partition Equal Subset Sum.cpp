const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
int dp[200 + 1][10000 + 4];
int n;
vector<int>v;
int tot;
bool can(int i, int sum){
    if(sum > tot / 2)
        return false;
    if(sum == tot - sum)
        return true;
    if(i == n)
        return false;
    int &ret = dp[i][sum];
    if(~ret)
        return ret;
    bool op1 = can( i + 1, sum);
    bool op2 = can(i + 1, sum + v[i]) ;
    return ret = op1||op2;
}
bool canPartition(vector<int>& nums) {
    n = nums.size();
    v = nums;
    tot = 0;
    for(int i = 0 ; i < n ; i++)
        tot+=v[i];
        if(tot & 1)
            return false;
    memset(dp, -1, sizeof dp);
   return can(0,0);
}

};
