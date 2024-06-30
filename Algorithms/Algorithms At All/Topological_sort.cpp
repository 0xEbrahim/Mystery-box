vector<vector<int>>adj;
vector<int>dist, parent;
vector<bool>vis;
vector<int>inDegree;
int n , m;

void BFS(){
    queue<int>q;
    for(int i = 1 ; i <= n ; i++){
        if(inDegree[i] == 0){
            q.push(i);
            vis[i] = true;
        }
    }
    while(not q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(auto &it : adj[node]){
            if(!vis[it]){
                inDegree[it]--;
                if(inDegree[it] == 0) {
                    vis[it] = true;
                    q.push(it);

                }
            }
        }
    }
}

void Still_Up() {
    cin >> n >> m ;
    adj.assign(n + 1 , vector<int>());
    vis.assign(n + 1 , false);
    inDegree.assign(n + 1 , 0);
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        inDegree[v]++;
    }
}
