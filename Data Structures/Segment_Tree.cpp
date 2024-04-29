struct Node {
    int min;

    Node(){
        min = LLONG_MAX;
    }

    Node(int x){
        min = x;
    }

    void change(int x){
        min = x;
    }

};

struct shagarty {
    shagarty(int n){

        N = 1;

        while(N < n)
            N *= 2;

        seg.assign(2 * N, Node());
    }
private:
    int N;
    vector<Node>seg;
    // can be changed
    Node merge(Node & l, Node & r){
        Node ans = Node();
        ans.min = min(l.min , r.min);
        return ans;
    }

    // 0 - indexed & r is not included
    void set(int idx, int value, int node, int l, int r){

        if(r - l == 1) {
            seg[node].change(value);
            return;
        }

        int mid = (l + r) / 2;

        if(idx < mid)
            set(idx, value, 2 * node + 1, l, mid);
        else
            set(idx, value, 2 * node + 2, mid , r);

        seg[node] = merge(seg[2 * node + 1], seg[2 * node + 2]);
    }

    // 0 - indexed & r is not included
    Node get(int l, int r, int st, int ed, int node){

        if(st >= l && ed <= r){
            return seg[node];
        }
        if(st >= r || ed <= l)
            return Node();

        int mid = (st + ed) / 2;
        Node left = get(l, r, st, mid, 2 * node + 1);
        Node right = get(l, r , mid , ed , 2 * node + 2);
        return merge(left, right);
    }
public:
    void set(int idx, int val){
        set(idx, val, 0, 0 , N);
    }
    int get(int l , int r){
        return get(l, r, 0, N, 0).min;
    }
};
