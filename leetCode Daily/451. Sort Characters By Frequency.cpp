class Solution {
public:
    string frequencySort(string s) {
    map<char ,  int>mp;
    int n = s.size();
    for(int i = 0 ; i < n ; i++){
        mp[s[i]]++;
    }
    vector<pair<int, char>>v;
    for(auto &i : mp){
        v.push_back({i.second, i.first});
    }
   sort(v.rbegin(), v.rend());
    string ans = "";
    for(auto &i : v){
        for(int j = 0 ; j < i.first ; j++){
            ans += i.second;
        }
    }
    return ans;
}
};
