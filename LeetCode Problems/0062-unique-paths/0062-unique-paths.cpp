class Solution {
public:
    int dp[150][150];
    int cnt = 0;
    bool valid(int i , int j , int n , int m){
        return (i >= 0 && i < n) && ( j < m && j >= 0);
    }
    int solve(int i , int  j , int n , int m){
        if(!valid(i,j,n,m)){
            return 0;
        }
        if(i == n-1 && j == m-1){
            return 1;
        }
        int &ret = dp[i][j];
        if(~ret)
            return ret;
        int right = 0 , down = 0;
        right += solve(i , j + 1 , n , m);
        down += solve(i + 1 , j , n , m);
        return ret = (right + down);
    }
    int uniquePaths(int m, int n) {
        memset(dp , -1 , sizeof dp);
        return solve(0,0,m,n);
    }
};