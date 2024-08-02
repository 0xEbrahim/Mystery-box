struct Node {
    ll sum;
    Node(){
        sum = 0;
    }

    Node(ll x){
        sum = x;
    }

    void change(ll x){
        sum = x;
    }

};

struct shagarty {
    shagarty(ll n){
        N = 1;
        while(N < n)
            N *= 2;
        seg.assign(2LL * N, Node());
    }
private:
    ll N;
    vector<Node>seg;
    // can be changed
    Node merge(Node & l, Node & r){
        Node ans = Node();
        ans.sum = l.sum + r.sum;
        return ans;
    }

    // 0 - indexed & r is not included
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

    // 0 - indexed & r is not included
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
public:
    void set(ll idx, ll val){
        set(idx, val, 0, 0 , N);
    }
    ll get(ll l , ll r){
        return get(l, r, 0, N, 0).sum;
    }
    void build(vector<ll>&a){
        build(a , 0,0,N);
    }
};
