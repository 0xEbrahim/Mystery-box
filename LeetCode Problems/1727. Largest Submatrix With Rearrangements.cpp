const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    int minAreaRect(vector<vector<int>>& v) {
       int ans = INT_MAX;
        map<int , set<int>>mp;
        for(int i = 0 ; i < v.size() ; i++){
            mp[v[i][0]].insert(v[i][1]);
        }
        for(int i = 0 ; i < v.size() ; i++){
            for(int j = i + 1 ; j < v.size() ; j++){
                if(v[i][0] == v[j][0] || v[i][1] == v[j][1])
                    continue;
                if(mp[v[i][0]].count(v[j][1]) && mp[v[j][0]].count(v[i][1])){
                    ans = min(ans, abs(v[i][0] - v[j][0]) * abs(v[i][1] - v[j][1]));
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
