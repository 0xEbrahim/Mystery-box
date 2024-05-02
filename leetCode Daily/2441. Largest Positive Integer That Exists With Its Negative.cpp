class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int pos[1000 + 2] = {},neg[1000 + 2] = {};
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] < 0){
                neg[nums[i] * -1]++;
            }else
            pos[nums[i]]++;
        }
        int mx = -1;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i]>0 && pos[nums[i]] && neg[nums[i]])
                mx = max(mx, nums[i]);
        }
        return mx;
    }
};
