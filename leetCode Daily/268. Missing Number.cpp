class Solution {
public:
    int missingNumber(vector<int>& v) {
        int n = v.size();
        int ans = n;
        for(int i = 0 ; i < n ; i++){
            ans ^= i;
            ans ^= v[i];
        }
        return ans;
    }
};
