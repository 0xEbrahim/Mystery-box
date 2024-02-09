class Solution {
public:


int lis(int i , int prev_i , vector<int>&v , int n , vector<vector<int>>&memo){
    if(i == n)
        return 0;
        int &ans = memo[i][prev_i + 1];
    if( ans != -1) 
        return ans;
     ans = lis(i + 1 , prev_i , v, n , memo);
    if(prev_i == -1 || v[i] > v[prev_i])
        ans = max(ans , lis(i + 1 , i , v , n, memo) + 1);
    return ans;
}
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size() , vector<int>(nums.size() + 1 , -1));
       return lis(0 , -1 , nums , nums.size(), dp);
    }
};