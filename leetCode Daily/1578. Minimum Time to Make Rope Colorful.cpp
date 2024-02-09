class Solution {
public:

   int minCost(string s, vector<int>& t) {
   int l = 0 ,ans = 0, r = 1;
   while(r < s.size()){
       if(s[l] == s[r]){
           if(t[l] < t[r]){
               ans += t[l];
               l = r;
               r++;
           }else{
               ans += t[r];
               r++;
           }
       }else{
           r++;
           l = r-1;
       }
   }
   return ans;
}
};
