struct mergeSort{
    struct Node{
        vector<int> nums;
        Node(){
            nums.clear();
        }
        Node(int x){
            nums.push_back(x);
        }
    };

    vector<Node> segData;
    int treeSize;

    mergeSort(int n){
        treeSize = 1;
        while(treeSize < n)
            treeSize *= 2;
        segData.assign(2 * treeSize, Node());
    }

    Node merge(Node lf, Node ri){
        Node ans = Node();
        int idxL = 0, idxR = 0;
        while (1){
            if(idxL == lf.nums.size()){
                while(idxR < ri.nums.size()){
                    ans.nums.push_back(ri.nums[idxR++]);
                }
                break;
            }
            if(idxR == ri.nums.size()){
                while(idxL < lf.nums.size()){
                    ans.nums.push_back(lf.nums[idxL++]);
                }
                break;
            }

            if(lf.nums[idxL] <= ri.nums[idxR]){
                ans.nums.push_back(lf.nums[idxL++]);
            }
            else{
                ans.nums.push_back(ri.nums[idxR++]);
            }
        }
        return ans;
    }

    int get(int l, int r, int val, int nx, int lx, int rx){
        if(l <= lx && r >= rx) {
            return upper_bound(all(segData[nx].nums), val) - segData[nx].nums.begin();
        }
        if(r <= lx || l >= rx) return 0;
        int mid = lx + (rx - lx)/2;
        return get(l, r, val, 2 * nx + 1, lx, mid) + get(l, r, val, 2 * nx + 2, mid, rx);
    }

    int LessEqual(int l, int r, int val){
        return get(l, r, val, 0, 0, treeSize);
    }

    int Greater(int l, int r, int val){
        return r - l - LessEqual(l, r, val);
    }

    int Less(int l, int r, int val){
        return LessEqual(l, r, val - 1);
    }

    int GreaterEqual(int l, int r, int val){
        return r - l - LessEqual(l, r, val - 1);
    }

    void Build(vector<int> & v, int nx, int lx, int rx){
        if(rx - lx == 1){
            if(lx < v.size()){
                segData[nx]= Node(v[lx]);
            }
            return;
        }

        int mid = lx + (rx - lx)/2;

        Build(v, 2 * nx + 1, lx, mid);
        Build(v, 2 * nx + 2, mid, rx);

        segData[nx] = merge(segData[2 * nx + 1], segData[2 * nx + 2]);
    }

    void Build(vector<int> & v){
        Build(v, 0, 0, treeSize);
    }
};
