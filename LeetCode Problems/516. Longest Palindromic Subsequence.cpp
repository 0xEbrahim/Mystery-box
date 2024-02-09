class Solution {
public:
vector<vector<int>>dp;
int n;
string ans;
void build(int i , int j, string s){
    if(i > j || i > n || j < 0)
        return;
    if(i == j){
        ans.push_back(s[i]);
        return;
    }
    int &ret = dp[i][j];
    if(s[i] == s[j]){
        if(ret == dp[i + 1][j - 1] + 1)
        {
            ans.push_back(s[i]);
            build(i + 1, j - 1,s);
            ans.push_back(s[j]);
        }
    }else{
        if(ret == dp[i + 1][j])
            build(i + 1, j,s);
        else if(ret == dp[i][j - 1])
            build(i, j - 1,s);
    }
}
    int longestPalindromeSubseq(string s) {
         n = s.size();
    dp.resize(n + 1, vector<int>(n + 1 , 0));
    for(int i = 0 ; i < n ; i++){
        dp[i][i] = 1;
    }
    for(int i = n - 1 ; ~i ; i--){
        for(int j = i + 1 ; j < n ; j++){
            if(i >= j){
                dp[i][j] = 1;
                continue;
            }
            if(s[i] == s[j]){
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }else{
                dp[i][j] = max(dp[i + 1][j] , dp[i][j - 1]);
            }
        }
    }
    ans.clear();

    return dp[0][n-1];
    }
};
