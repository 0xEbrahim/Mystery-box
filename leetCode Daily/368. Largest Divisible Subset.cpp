class Solution {
public:
int dp[1000 + 5][1000 + 5];
int n;
vector<int>v, ans;
int solve(int cur, int lst){
    if(cur == n)
        return 0;
    int &ret = dp[cur][lst + 1];
    if(~ret)
        return ret;
    int op1 = solve(cur + 1, lst);
    int op2 = 0;
    if(lst == -1 || (v[cur] % v[lst] == 0))
        op2 = solve(cur + 1, cur) + 1;
    return ret = max(op1, op2);
}
void build(int cur, int lst){
    if(cur == n)
        return;
    int ret = solve(cur, lst);
    if(lst == -1 || (v[cur] % v[lst] == 0)) {
        if (ret == solve(cur + 1, cur) + 1) {
            ans.push_back(v[cur]);
            build(cur + 1, cur);
        }else
            build(cur + 1, lst);
    }else
        build(cur + 1, lst);
}
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n = nums.size();
    memset(dp, -1, sizeof dp);
    v = nums;
   sort(v.begin(), v.end());
   solve(0,-1);
   build(0,-1);
   return ans;
    }
};
