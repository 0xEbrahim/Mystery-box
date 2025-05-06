int n, sq;
vector<int> v;
vector<vector<int>> dat;
vector<int> blk;

void process() {
    for (int i = 0; i < n; i++) {
        dat[i / sq].push_back(v[i]);
        blk[i / sq] += v[i];
    }
}

void update(int i, int k) {
    int pos = i / sq;
    v[i] = k;
    i -= pos * sq;
    dat[pos][i] = k;
    int sum = 0;
    for (int j = 0; j < dat[pos].size(); j++)
        sum += dat[pos][j];
    blk[pos] = sum;
}

int get(int l, int r) {
   int ans = 0;
   while(l <= r){
       if(l % sq == 0 && l + sq <= r){
           ans += blk[l / sq];
           l += sq;
       }else{
           ans += v[l];
           l++;
       }
   }
   return ans;
}

void done() {
    int q;
    cin >> n >> q;
    v.resize(n);
    for (auto &it: v)
        cin >> it;
    sq = sqrtl(n);
    dat.resize(n + 1);
    blk.resize(n + 1);
    process();
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int idx;
            cin >> idx;
            idx--;
            int b;
            cin >> b;
            update(idx, b);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << get(l, r) << endl;
        }
    }
}
