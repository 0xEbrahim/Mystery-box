int N = 1e5 + 5;
int Log = 23;
vector<vector<int>>adj;
struct  LCA{
    vector<vector<int>>anc;
    vector<int>lvl;
public:
    LCA(){
        anc.assign(N, vector<int>(Log));
        lvl.assign(N, 0);
    }
    void build(int node, int par){
        lvl[node] = lvl[par] + 1;
        anc[node][0] = par;
        for(int i = 1 ; i < Log ; i++){
            int p = anc[node][i - 1];
            anc[node][i] = anc[p][i - 1];
        }
        for(auto &it : adj[node]){
            if(it != par)
                build(it, node);
        }
    }

    int getKthAnc(int node, int k){
        for(int i = Log - 1 ; ~i ; i--){
            if((k >> i) & 1)
                node = anc[node][i];
        }
        return node;
    }

    int get_lca(int u, int v){
        if(lvl[u] < lvl[v]) swap(u, v);
        u = getKthAnc(u, lvl[u] - lvl[v]);
        if(u == v) return u;
        for(int i = Log - 1 ; ~i ; i--){
            if(anc[u][i] != anc[v][i]) {
                u = anc[u][i];
                v = anc[v][i];
            }
        }
        return anc[v][0];
    }

    int get_dist(int u , int v){
        int lca = get_lca(u, v);
        int distance = lvl[u] + lvl[v] - 2 * lvl[lca];
        return distance;
    }
};
