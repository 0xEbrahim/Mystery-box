
const int  MX = 2e5+20,INF=1e18;
int n , m , st , ed;
vector<int>d;
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
            }
        }
    }
}
