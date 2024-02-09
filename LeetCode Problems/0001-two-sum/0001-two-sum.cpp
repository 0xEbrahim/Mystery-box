class Solution {
public:
   vector<int> twoSum(vector<int>& v, int target) {
   map<int ,int>mp;
    for(int i = 0 ; i < v.size() ; i++){
        if(mp.find(target-v[i]) == mp.end()){
            mp[v[i]] = i;
        }else{
            return {i,  mp[target-v[i]]};
        }
    }
    return {-1,-1};
}
};