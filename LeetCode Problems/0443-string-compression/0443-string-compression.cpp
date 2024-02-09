class Solution {
public:
    int compress(vector<char>& v) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(v.size()==1){
            return 1;
        }
        int cnt = 0 ;
        int l = 0 , r = 0 ;
        
        string s="";
         while(r < v.size()){
             if(v[r] == v[l]){
                 r++;
                 cnt++;
             }else if(v[r] != v[l]){
                string xx = to_string(cnt);
                s+=v[r-1];
               if(cnt>1){ s+=xx;}
                 l = r;
                 cnt = 0;
             }
         }
         s+=v[r-1];
         string xx = to_string(cnt);
        if(cnt>1){ s+=xx;}

         v.clear();
         for(int i = 0 ; i < s.size() ; i++){
             v.push_back(s[i]);
         }
         return v.size();
    }
};