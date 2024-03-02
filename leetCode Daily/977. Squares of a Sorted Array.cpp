class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int freq[10000 + 1] = {0};
        int mx = 0;
        vector<int>ans;
        for(int i = 0 ; i < n ; i++)
            freq[abs(nums[i])]++, mx = max(mx, abs(nums[i]));
        for(int i = 0 ; i <= mx ; i++)
            while(freq[i]--){
                ans.push_back(i * i);
            }
            return ans;
    }
};
