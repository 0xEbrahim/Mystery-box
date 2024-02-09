class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,int>>v;
        for(int i = 0 ; i < strs.size() ; i++)
            {
                v.push_back({strs[i],i});
            }
        for(int i = 0 ; i < v.size() ; i++){
            sort(v[i].first.begin() , v[i].first.end());
        }
        sort(v.begin(),v.end());
        int l = 0 , r = 0;
        vector<vector<string>>ans;
        vector<string>tmp;
        while(r < v.size()){
            if(v[r].first == v[l].first){
                tmp.push_back(strs[v[r].second]);
                r++;
            }else {
                ans.push_back(tmp);
                tmp.clear();
                l = r;
            }
        }
        ans.push_back(tmp);
        return ans;
    }
};