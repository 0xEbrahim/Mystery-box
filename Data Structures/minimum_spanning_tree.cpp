int N = 1e5 + 10;
vector<int>par(N),sz(N);
vector<vector<int>>adj;
vector<bool>vis;
int comps;
int n , m;

int find(int nd){
    if(nd == par[nd])
        return nd;
    else
        return par[nd] = find(par[nd]);
}
bool connected(int u , int v)
{
    return find(u) == find(v) ;
}

void join(int u , int v){
    u = find(u);
    v = find(v);
    if(sz[u] < sz[v])
        swap(u,v);
    par[v] = u;
    sz[u] += sz[v];
}

struct edge{
    int u , v , w;

};

bool cmp(edge x , edge y){
    return x.w < y.w;
}
ull kruskal(vector<edge>&edges){
    sort(edges.begin(),edges.end(),cmp);
    ull sum = 0 ;
    for(auto i : edges){
       if(!connected(i.u,i.v)){
           sum+=i.w;
           join(i.u,i.v);
       }
    }
    return sum;
}
