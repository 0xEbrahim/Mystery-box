const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
/*
  When I wrote this, only Allah and I understood what I was doing
  Now, only Allah knows
*/
bool vis[100000 + 5];
int res = 0 ;
void dfs(int node, vector<vector<int>> & adj){
    vis[node] = true;
    res++;
    for(auto &_ : adj[node]){
        if(!vis[_])
          dfs(_, adj);
    }
}
long long countPairs(int n, vector<vector<int>>& v) {
    vector<vector<int>>adj(n + 1);
    for(int i = 0 ; i < v.size() ; i++){
        adj[v[i][0] ].push_back(v[i][1] );
        adj[v[i][1] ].push_back(v[i][0] );
    }
    long long ans = 0, cnt = 0, count = 0;
    for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
            cnt++;
            res = 0;
            dfs(i, adj);
            if(cnt == 1)
                count += res;
            else
                ans += count * res, count+= res;
        }
    }
    return ans;
}
};
