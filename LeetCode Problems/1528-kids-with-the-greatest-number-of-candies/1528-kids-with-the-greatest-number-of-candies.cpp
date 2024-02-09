class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& v, int ex) {
        int x = *max_element(v.begin(),v.end());
        vector<bool>ans(v.size());
        for(int i = 0 ; i < v.size() ; i++){
            ans[i] = (v[i]+ex >= x);
        }
        return ans;
    }
};