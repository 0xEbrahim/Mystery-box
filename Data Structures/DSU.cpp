int N = 1e5 + 10;
vector<int>par,sz;
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
    if(u == v)
        return;
    if(sz[u] < sz[v])
        swap(u,v);
    par[v] = u;
    sz[u] += sz[v];
}
