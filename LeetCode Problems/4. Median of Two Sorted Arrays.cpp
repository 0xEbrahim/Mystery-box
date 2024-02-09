class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0 , j = 0 ;
        vector<int>merged;
        int n = nums1.size();
        int m = nums2.size();
        while(i < n && j < m){
            if(nums1[i] <= nums2[j]){
                merged.push_back(nums1[i++]);
            }else{
                merged.push_back(nums2[j++]);
            }
        }
        while(i < n){
            merged.push_back(nums1[i++]);
        }
        while(j < m){
            merged.push_back(nums2[j++]);
        }
        double ans = 0.0;
        int sz = merged.size();
        if(sz == 0)
            return 0;
        if(sz&1)
            return merged[sz/2] * 1.00000;
        else{
            return ((merged[sz/2] + merged[sz/2 - 1]) * 1.00000)/2.00000;
        }    
    }
};
