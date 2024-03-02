class Solution {
public:
/*
  When I wrote this, only Allah and I understood what I was doing
  Now, only Allah knows
*/
vector<vector<int>>adj;
vector<int>t;
int dp[5 * 10000 + 3];
int dfs(int node){
    int &ret = dp[node];
    if(~ret)
        return ret;
    ret = 0;
    for(auto &i : adj[node]){
        ret = max(ret, t[ i - 1] + dfs(i));
    }
    return ret ;
}
int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    adj.clear();
    adj.resize(5 * 10000 + 10);
    t = time;
    int nn = relations.size();
    for(int i = 0 ; i < nn ; i++)
        adj[relations[i][0]].push_back(relations[i][1]);
    memset(dp, -1, sizeof dp);
    int ans = 0 ;
    for(int i = 1 ; i <= n ; i++){
        ans = max(ans, dfs(i) + t[i - 1]);
    }
    return ans;
}
};
