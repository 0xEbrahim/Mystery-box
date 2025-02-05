struct dsu {
    vector<int> par, size;
    int cnt;
    void init(int n) {
        cnt = 0;
        par.resize(n + 1, -1);
        size.resize(n + 1, 0);
    }
    void init_all(int n) {
        cnt = n;
        par.resize(n + 1);
        size.assign(n + 1, 1);
        for (int i = 1; i <= n; ++i) par[i] = i;
    }
    int find_root(int u) {
        if (par[u] == u) return u;
        return par[u] = find_root(par[u]);
    }
    bool is_connected(int u, int v) {
        return find_root(u) == find_root(v);
    }
    void make_set(int u) {
        if (~par[u]) return;
        par[u] = u;
        cnt++;
        size[u] = 1;
    }
    bool merge(int u, int v) {
        int root_u = find_root(u);
        int root_v = find_root(v);
        if (root_u == root_v) return 0;
        if (size[root_u] > size[root_v])
            swap(root_u, root_v);
        size[root_v] += size[root_u];
        par[root_u] = root_v;
        --cnt;
        return 1;
       }
};
