vector<vector<int>>adj;
vector<int>vis;
bool detect_cycle(int node){
    vis[node] = 1;
    for(auto &child : adj[node]) {
        if(vis[child] == 0){
            if(detect_cycle(child))
                return true;
        }else if (vis[child] == 1){
                return true;
        }
    }
    vis[node] = 2;
    return false;
}
