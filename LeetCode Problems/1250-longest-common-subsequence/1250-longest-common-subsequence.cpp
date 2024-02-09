class Solution {
public:
string s1 , s2;
int memo[1005][1005];
int solve(int i , int j){
if(i == s1.size() || j == s2.size())
return 0;
int &ret = memo[i][j];
if(~ret) return ret;
if(s1[i] == s2[j])
ret = solve(i + 1 , j + 1) + 1;
else 
ret = max(solve(i + 1 , j) , solve(i , j+ 1));
return ret;
}

    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1 , s2 = text2;
memset(memo , -1 , sizeof memo);
        return solve(0 , 0);
    }
};