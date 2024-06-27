vector<vector<int>>adj;
vector<bool>vis;
bool detect_cycle(int node, int parent){
    vis[node] = true;
    for(auto &child : adj[node]){
        if(!vis[child]) {
            if (detect_cycle(child, node))
                return true;
        }else if (child != parent)
                    return true;

    }
    return false;
}
