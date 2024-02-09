class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        if(v.size() == 0)return 0;
        int mx = 0;
        int cnt = 0;
       set<int>s(v.begin() , v.end());
        for(int i = 0 ; i < v.size() ; i++){
            if(!s.count(v[i]-1)){
                cnt = 0;
                while(s.count(v[i] + cnt)){
                    cnt++;
                }
                mx = max(cnt,mx);
                cnt=0;
            }
        }
        return mx;
    }
};