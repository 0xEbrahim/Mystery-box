class Solution {
public:
   
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool>vis;
        bool flag = false;
        for(int i = 0 ; i < nums.size() ;  i++){
            if(vis[nums[i]]){
                flag = true;
                break;
            }
            vis[nums[i]] = true;
        }
        return flag;
    }
};