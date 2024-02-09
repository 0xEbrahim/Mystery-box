class Solution {
public:
    int n , m ;

int dp[205][205];
int solve(int i , int j, vector<vector<int>> & v){
    if(i>n-1 || j>m-1) return INT_MAX;
    if(i==n - 1 && j== m - 1) return v[i][j];
    int &ret = dp[i][j];
    if(~ret)
        return ret;
    int op1 = 0;
    op1 += solve(i , j + 1 , v );
    int op2 = 0;
    op2 += solve(i + 1 , j , v);
    return ret = min(op1 , op2) + v[i][j];
}
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1 , sizeof dp);
        n = grid.size();
        m = grid[0].size();
        return solve(0,0,grid);
    }
};
