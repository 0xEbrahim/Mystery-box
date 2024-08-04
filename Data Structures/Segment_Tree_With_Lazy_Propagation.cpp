struct Node{
    ll val;
    ll lazy;
    bool is_lazy ;

    // put values that don't affect any operations
    Node(){
        val = 0;
        lazy = 0;
        is_lazy = false;
    }
    Node(ll x){
        val = x;
        lazy = 0;
        is_lazy = false;
    }

    // What happens when you want to update ??
    void change(ll x){
        val = x;
        lazy = x;
        is_lazy = true;
    }
};

struct Shagarty{
    vector<Node>seg;
    int N;
    Shagarty(int n){
        N = 1;
        while(N < n)
            N*=2;
        seg.assign(2 * N,Node());
    }

    // change it to serve your thoughts
    Node merge(Node left, Node right){
        Node ans = Node();
        ans.val = left.val + right.val;
        return ans;
    }


    // -------------------------------------------- //

    void propagate(int lx, int rx, int node){
        if(rx - lx == 1 || !seg[node].is_lazy)
            return;

        seg[2 * node + 1].change(seg[node].lazy);
        seg[2 * node + 2].change(seg[node].lazy);

        seg[node].is_lazy = false;
        seg[node].lazy = 0;
    }


    // -------------------------------------------- //

    void set(int lx, int rx, int node, int l, int r, ll val){
        propagate(lx, rx, node);
        if(lx >= l && rx <= r){
            seg[node].change(val);
            return;
        }
        if(lx >= r || rx <= l) return;
        ll mid = (rx + lx) / 2;
        set(lx, mid, 2 * node + 1, l,r,val);
        set(mid, rx, 2 * node + 2, l , r, val);
        seg[node] = merge(seg[2 * node + 1], seg[2 * node + 2]);
    }

    // -------------------------------------------- //

    Node get(int lx, int rx, int node, int l, int r){
        propagate(lx, rx, node);
        if(lx >= l && rx <= r)return seg[node];
        if(lx >= r || rx <= l) return Node();
        ll mid = (lx + rx) / 2;
        Node left = get(lx, mid, 2 * node + 1, l , r);
        Node right = get(mid, rx, 2 * node + 2, l , r);
        return merge(left, right);
    }

    // -------------------------------------------- //

    void build(int lx, int rx, int node, vector<int>&v){
        if(rx - lx == 1){
            if(lx < v.size())
                seg[node].change(v[lx]);
            return;
        }
        int mid = (lx + rx) / 2;
        build(lx, mid, 2 * node + 1, v);
        build(mid, rx, 2 * node + 2, v);
    }


    // -------------------------------------------- //
    ll get(int l, int r){
        return get(0, N, 0, l, r).val;
    }
    void set(int l , int r, ll val){
        set(0, N, 0, l , r, val);
    }
    void build(vector<int>&v){
        build(0, N, 0, v);
    }
};
