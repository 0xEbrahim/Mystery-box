struct Node {
    ll mx ;
    Node(){
        mx = 0;
    }

    Node(ll x){
        mx = x;
    }

    void change(ll x){
        mx = x;
    }

};

struct Shagarty {
    Shagarty(ll n){
        N = 1;
        while(N < n)
            N *= 2;
        seg.assign(2LL * N, Node());
    }
private:
    ll N;
    vector<Node>seg;
   
    Node merge(Node & l, Node & r){
        Node ans = Node();
        ans.mx = max(l.mx , r.mx);
        return ans;
    }
    
    void set(ll idx, ll value, ll node, ll l, ll r){
        if(r - l == 1) {
            seg[node].change(value);
            return;
        }

        ll mid = (l + r) / 2LL;

        if(idx < mid)
            set(idx, value, 2 * node + 1, l, mid);
        else
            set(idx, value, 2 * node + 2, mid , r);

        seg[node] = merge(seg[2 * node + 1], seg[2 * node + 2]);
    }

   
    Node get(ll l, ll r, ll st, ll ed, ll node){
        if(st >= l && ed <= r){
            return seg[node];
        }
        if(st >= r || ed <= l)
            return Node();
        ll mid = (st + ed) / 2;
        Node left = get(l, r, st, mid, 2 * node + 1);
        Node right = get(l, r , mid , ed , 2 * node + 2);
        return merge(left, right);
    }
    void build(vector<ll>&v, ll node, ll l, ll r){
        if(r - l == 1){
            if(l < (int)v.size()){
                seg[node].change(v[l]);
            }
            return;
        }
        ll mid = (l + r) / 2;
        build(v, 2 * node + 1, l, mid);
        build(v , 2 * node + 2, mid, r);
        seg[node] = merge(seg[2 * node + 1], seg[2 * node + 2]);
    }
    ll find_Kth(ll l, ll r, ll node, ll k){
        if(r - l  == 1 )
            return l;
        ll mid = (r + l) / 2;
        if(k <= seg[2 * node + 1].mx)
            return find_Kth(l, mid, 2 * node + 1, k);
        else
            return find_Kth(mid, r, 2 * node + 2, k - seg[2 * node + 1].mx);
    }
    int max_eq(int node, int l, int r, int ql, int qr, int x) {
        if (r < ql || l > qr || seg[node].mx < x) return -1;

        if (l == r) return l;

        int mid = (l + r) / 2;
        int left = max_eq(2 * node + 1, l, mid, ql, qr, x);
        if (left != -1) return left;
        return max_eq(2 * node + 2, mid + 1, r, ql, qr, x);
    }
public:
    void set(ll idx, ll val){
        set(idx, val, 0, 0 , N);
    }
    ll get(ll l , ll r){
        return get(l , r , 0 , N,0).mx;
    }
    void build(vector<ll>&a){
        build(a , 0,0,N);
    }
    ll find_Kth(int k){
        return find_Kth(0,N,0,k);
    }
    int max_eq(int ql, int qr, int x) {
        return max_eq(0, 0, N , ql, qr, x);
    }
};
