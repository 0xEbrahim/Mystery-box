class Solution {
public:
bool isValid(int i , int j , int n , int m){
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
       int n = img.size();
    int m = img[0].size();
    vector<vector<int>>ans(n, vector<int>(m));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            int cnt = 1 ;
            int sum = img[i - 1][j - 1];
            for(int k = 0 ; k < 8 ; k++){
                if(isValid(i + dx[k] , j + dy[k] , n , m)){
                    sum += img[i + dx[k] - 1][j + dy[k] - 1];
                    cnt++;
                }
            }
            ans[i - 1][j - 1] = (sum/cnt);
            }
        }
    return ans;
        }  
};
