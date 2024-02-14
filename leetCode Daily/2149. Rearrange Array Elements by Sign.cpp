class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        vector<int>p,n;
        for(int i = 0 ; i < v.size() ; i++){
            if(v[i] < 0)
                n.push_back(v[i]);
            else
                p.push_back(v[i]);
        }
        bool x = true;
        vector<int>ans;
        int xx = 0;
        int i = 0 , j  = 0 ;
        while(j < n.size()){
            if(x){
                ans.push_back(p[i++]);
                x = false;
            }else{
                x = true;
                ans.push_back(n[j++]);
            }
        }
        return ans;
    }
};
