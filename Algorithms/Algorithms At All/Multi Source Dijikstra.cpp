const int  MX = 2e5+20,INF=1e18;
int n , m , st ,id = 0, ed , mn;

vector<int>d;
vector<vector<pair<int , int>>>adj;

void dij(){
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<>>q;

    for(int i = 1 ; i <= n ; i++){
        q.push({d[i] , i});
    }

    while(!q.empty()){
        int cost = q.top().first;
        int node = q.top().second;
        q.pop();

        if(d[node] < cost)
            continue;

        for(auto ch : adj[node]){
            int ncost = cost + ch.second;
            if(d[ch.first] > ncost ){
                d[ch.first] = ncost;
                q.push({ncost, ch.first});
            }
        }
    }
}
