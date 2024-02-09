const int  MX = 2e5+20,INF=1e18;
int n , m , st ,id = 0, ed;
vector<int>d;
vector<int>p;
vector<vector<pair<int , int>>>adj;

void dijikstra(int src){
    priority_queue<pair<int , int> , vector<pair<int,int>>, greater<>>q;
    q.push({0,src});
    for(int i = 1 ; i <= n ; i++){
        d[i] = INF;
    }
    d[src] = 0;
    while(!q.empty()){
        int cost = q.top().first;
        int nd = q.top().second;
        q.pop();

        if(d[nd] < cost)
            continue;
        for(auto ch : adj[nd]){
            int newCost = ch.second + cost;
            if(newCost < d[ch.first]){
                d[ch.first] = newCost;
                q.push({d[ch.first] , ch.first});
                p[ch.first] = nd;
            }
        }
    }
}

void HANMA_BAKI() {
    cin >> n >> m;
    d.resize(n + 1);
    adj.resize(n + 1);
    p.resize(n + 1);
    for(int i = 0 ; i < m ; i++){
        int u , v , c;
        cin >> u >> v >> c;
        adj[u].pb({v , c});
        adj[v].pb({u , c});
    }
    dijikstra(1);
   int x = d[n];
   if(x == INF){
       cout << -1 ;
       return;
   }
    vector<int>path;
    path.pb(n);
    while(p[n]){
        path.pb(p[n]);
        n = p[n];
    }

    std::reverse(path.begin(), path.end());
    for(auto &i : path)cout << i << " ";
}
