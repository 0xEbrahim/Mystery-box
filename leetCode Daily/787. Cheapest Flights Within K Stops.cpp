#define ll long long
class Solution {
public: 
vector<vector<pair<int, int>>>adj;
int dp[101][101];
int ed;
int lst;

int dfs(int node, int cnt){
    if(node == ed)
        return 0;
    if(cnt > lst)
        return 1e9;
    int &ret = dp[node][cnt];
    if(~ret)
        return ret;
    ret = 1e9;
    for(auto &i : adj[node]){
        ret = min(ret, dfs(i.first,cnt + 1) + i.second);
    }
    return ret;
}
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    adj.clear();
    ed = dst;
    adj.resize(n);
    for(int i = 0 ; i < flights.size() ; i++){
        int u = flights[i][0];
        int v = flights[i][1];
        int w = flights[i][2];
        adj[u].push_back({v, w});
    }
    memset(dp, -1, sizeof dp);
    lst = k;
    int res = dfs(src, 0);
    return res >= 1e9 ? -1 : res;
}
};
