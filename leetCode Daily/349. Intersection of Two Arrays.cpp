class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int freq[1000 + 2] = {0};
        for(int i = 0; i < nums1.size() ; i++){
            if(!freq[nums1[i]])
            freq[nums1[i]]++;
            }
            vector<int>ans;
            for(int i = 0 ; i < nums2.size() ; i++)
                if(freq[nums2[i]])ans.push_back(nums2[i]), freq[nums2[i]]--;
            return ans;
    }
};
