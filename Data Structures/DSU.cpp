struct DSU {
    vector<int>parent;
    vector<int>sz;
    void init(int n){
        parent.resize(n + 5);
        sz.resize(n + 5);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int u){
        if(u == parent[u])
            return u;
       return parent[u] = find(parent[u]);
    }
    bool is_connected(int u, int v){
        return find(u) == find(v);
    }
    void merge(int u , int v){
        int root_u = find(u);
        int root_v = find(v);
        if(root_u == root_v)
            return;
        if(sz[root_u] > sz[root_v])
            swap(root_u, root_v);
        parent[root_u] = root_v;
        sz[root_v] += sz[root_u];
   }
};
