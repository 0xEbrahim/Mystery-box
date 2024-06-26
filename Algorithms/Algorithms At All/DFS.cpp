vector<vector<int>>adj;
vector<bool>vis;
void dfs(int node){
    vis[node] = true;
    for(auto &child : adj[node]){
        if(!vis[child])
            dfs(child);
    }
}
