class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string ans = "";
        int i;
        for( i = 0 ; i < min(n,m) ; i++){
            ans+=word1[i];
            ans+=word2[i];
        }
        if(n > m){
            for(i ; i < n ; i ++){
                ans+=word1[i];
            }
        }else{
             for(i ; i < m ; i ++){
                ans+=word2[i];
            }
        }
        return ans;
    }
};