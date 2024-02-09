class Solution {
public:
    bool vis[1000+20];
void dfs(int nd,vector<vector<int>>adj){
    vis[nd] = true;
    for(auto &ch : adj[nd]){
        if(!vis[ch])
            dfs(ch,adj);
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(0,rooms);
        for(int i = 0 ; i < rooms.size() ; i++){
            if(vis[i] == false)
                return false;
        }
    return true;;
}
};