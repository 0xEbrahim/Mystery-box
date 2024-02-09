class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
       set<int>s;
       int n = points.size();
       for(int i = 0 ; i < n ;i++){
           if(!s.count(points[i][0])){
               s.insert(points[i][0]);
           }
       }
        int mx = 0;
        vector<int>v(s.begin(), s.end());
        for(int i = 1 ; i < v.size() ; i++){
            mx = max(mx, abs(v[i] - v[i - 1]));
        }
        return mx;
    }
};
