class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int containZeros = 0;
       long long prod = 1;
       for(int i = 0 ; i < nums.size() ; i++){
           if(nums[i] == 0)containZeros += 1;
           if(nums[i] != 0)prod*=nums[i];
       }
       vector<int>ans;
       for(int i = 0 ; i < nums.size() ;  i++){
           if(nums[i]!=0 && containZeros==1){
               ans.push_back(0);
           }else if(nums[i] == 0 && containZeros==1){
                ans.push_back(prod);
           }
       }
       if(containZeros>1){
           for(int i = 0 ; i < nums.size() ; i++)ans.push_back(0);
       }
       if(!containZeros){for(int i = 0 ; i < nums.size() ; i++){
            ans.push_back(prod/nums[i]);
       }}
    return ans;
    }
};