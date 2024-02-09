struct SegTree{

    struct Node
    {
        long long val;
        long long lazy;

        Node():val(0), lazy(0){}

    };

    int tree_size, n;
    vector<Node> seg_data;
    Node neutral = Node();

    SegTree(int nn)
    {
        tree_size = 1;
        while (tree_size < nn) tree_size *= 2;
        seg_data.assign(tree_size<<1, neutral);
        n = nn;
    }

    void propagate(int node, int lx, int rx)
    {
        if(seg_data[node].lazy == 0 )
            return;

        seg_data[node].val += seg_data[node].lazy *(long long)(rx -lx +1 );

        if(lx == rx){
            seg_data[node].lazy = 0;
            return;
        }

        int mid = lx + (rx - lx) / 2;
        int next_node=2*node;
        seg_data[next_node].lazy += seg_data[node].lazy;
        seg_data[next_node + 1].lazy += seg_data[node].lazy;

        seg_data[node].lazy = 0;
    }

    void build(int node , int l ,int r){

        if(l == r) {
            seg_data[node].val = 0;
            return;
        }

        int mid = (l + r) / 2;
        int next_node=2*node;

        build(next_node , l , mid);
        build(next_node + 1 , mid+1 ,r);

        seg_data[node].val = seg_data[next_node].val + seg_data[next_node+1].val ;

    }

    void set(int l, int r, long long val, int node, int lx, int rx)
    {

        propagate(node , lx , rx);

        if(rx < l || lx > r)
            return;
        if(lx >= l && rx <= r) {
            seg_data[node].val += (long long)(rx - lx + 1)*val;

            int next_node = 2 * node;
            if(lx != rx){
                seg_data[ next_node ].lazy +=val;
                seg_data[ next_node + 1].lazy +=val;
            }

            return;
        }

        int mid = (lx + rx) / 2;
        int next_node = 2 * node;

        set(l,r,val,next_node , lx,mid );
        set(l,r,val,next_node + 1,mid+1 ,rx);


        seg_data[node].val = seg_data[next_node ].val +  seg_data[next_node + 1].val;
    }

    long long get(int l, int r, int node, int lx, int rx)
    {

        propagate(node , lx , rx);

        if(rx < l || lx > r)
            return 0;
        if(lx >= l && rx <= r)
            return seg_data[node].val;


        int mid = lx + (rx - lx) / 2;
        int next_node = 2*node;
        long long part1 = get(l, r, next_node , lx, mid);
        long long part2 = get(l, r, next_node + 1, mid+1, rx);

        return part1 + part2;
    }



};
