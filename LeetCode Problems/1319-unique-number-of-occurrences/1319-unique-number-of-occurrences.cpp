class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int ,int>mp;
        for(int i = 0 ; i < arr.size() ; i++){
            mp[arr[i]]++;
        }
        set<int>st;
        for(int i = 0 ; i < arr.size() ; i++){
            st.insert(mp[arr[i]]);
        }
        return st.size() == mp.size();
    }
};