class Solution {
public:
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
    comps--;
}
    int findCircleNum(vector<vector<int>>& v) {
        comps = v.size();
     comps = v.size();
    par.clear();
    sz.clear();
    par.resize(N);
    sz.resize(N);
    iota(par.begin(),par.end(),0);
    fill(sz.begin() , sz.end() , 1);
        for(int i = 0  ; i < v.size() ; i++){
            for(int j = 0 ; j < v.size() ; j++){
                if(v[i][j] == 1 && !connected(i,j))
                    join(i,j);
            }
        }
        return comps;
    }
};