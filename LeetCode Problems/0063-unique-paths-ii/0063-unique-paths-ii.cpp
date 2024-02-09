class Solution {
public:
int dp[150][150];
    int cnt = 0;
    bool valid(int i , int j , int n , int m , vector<vector<int>>&v){
        return (i >= 0 && i < n) && ( j < m && j >= 0) && v[i][j]!=1;
    }
    int solve(int i , int  j , int n , int m, vector<vector<int>>& s){
        if(!valid(i,j,n,m,s)){
            return 0;
        }
        if(i == n-1 && j == m-1){
            return 1;
        }
        int &ret = dp[i][j];
        if(~ret)
            return ret;
        int right = 0 , down = 0;
        right += solve(i , j + 1 , n , m,s);
        down += solve(i + 1 , j , n , m,s);
        return ret = (right + down);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& s) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,s.size() , s[0].size(),s);
    }
};