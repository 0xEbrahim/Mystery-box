class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int , int>>v;
        for(int i = 0 ; i < nums.size(); i++)
            v.push_back({nums[i], i});
        sort(v.begin(), v.end());
        vector<int>ans(nums.size());
        for(int i = 0 ; i < nums.size() ; i++){
            if(i && v[i].first == v[i - 1].first){
                    ans[v[i].second] = ans[v[i - 1].second];
            }else
                ans[v[i].second] = i;
            }
        return ans;
    }
};
