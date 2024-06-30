vector<vector<int>>adj;
vector<int>dist,color, parent;
vector<bool>vis;
vector<int>inDegree;

int n , m;

bool BFS(int nd){
   queue<int>q;
   q.push(nd);
   if(color[nd] == 0)
        color[nd] = 1;
   while(not q.empty()){
       int node = q.front();
       q.pop();
       for(auto &ch : adj[node]){
           if(color[ch] == 0){
               color[ch] = -color[node];
               q.push(ch);
           }else if(color[ch] == color[node])
               return false;
       }
   }
   return true;
}


void Still_Up() {
    cin >> n >> m ;
    adj.assign(n + 1 , vector<int>());
    color.assign(n + 1 , 0);
    inDegree.assign(n + 1 , 0);
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool can = true;
    for(int i = 1 ; i<= n ; i++){
        can &= BFS(i);
    }
    if(can){
        for(int i = 1 ; i <= n ; i++){
            cout << (color[i] == -1 ? 2 : 1) << " ";
        }
    }else
        cout <<"IMPOSSIBLE";
}
