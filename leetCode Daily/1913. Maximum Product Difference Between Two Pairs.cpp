class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
       int mx1 = INT_MIN, mx2 = INT_MIN, mn1 = INT_MAX, mn2 = INT_MAX;
       for(auto &el : nums){
           if(el > mx1){
               mx2 = mx1;
               mx1 = el;
           }else if(el > mx2){
               mx2 = el;
           }
           if(el < mn1){
               mn2 = mn1;
               mn1 = el;
           }else if(el < mn2){
               mn2 = el;
           }
       }
       return mx1 * mx2 - mn1 * mn2;
    }
};
