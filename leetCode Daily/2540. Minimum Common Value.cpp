class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1;
        for(int i = 0 ; i < nums1.size();  i++)
            s1.insert(nums1[i]);
        int ans = -1;
        for(auto &i : nums2)
            if(s1.count(i)){ans = i;break;}
        return ans;
    }
};
