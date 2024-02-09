class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1(nums1.begin(),nums1.end());
        set<int>s2(nums2.begin(),nums2.end());
        vector<vector<int>>ans;
        vector<int>t,s;
        for(auto it : s1){
            if(!s2.count(it))
                t.push_back(it);
       }
       for(auto it : s2){
            if(!s1.count(it))
                s.push_back(it);
        }
        ans.push_back(t);
        ans.push_back(s);
        return ans;
    }
};