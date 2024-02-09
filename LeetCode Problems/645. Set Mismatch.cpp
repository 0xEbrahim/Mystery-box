class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int>mp;
        vector<int>ans;
        bool f = false;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > 1 && !f){
                f = true;
                ans.push_back(nums[i]);
            }
        }
        for(int i = 1 ; i < 1e4 ; i++)
        if(!mp[i])
            {
                ans.push_back(i);
                break;
            }
        return ans;
    }
};
