struct Q {
    int l, r, i;
};

void compress(vector<int> &a, int start) {
    int n = a.size();
    vector<pair<ll, ll>> pairs(n);
    for (int i = 0; i < n; i++) {
        pairs[i] = {a[i], i};
    }
    sort(pairs.begin(), pairs.end());
    int nxt = start;
    for (int i = 0; i < n; i++) {
        if (i > 0 && pairs[i - 1].first != pairs[i].first) {
            nxt++;
        }
        a[pairs[i].second] = nxt;
    }
}

int sq = 448;
vector<int> freq;

void add(int i, int &ans) {
    if (++freq[i] == 1)
        ans++;
}

void erase(int i, int &ans) {
    if (--freq[i] == 0)
        ans--;
}

void done() {
    int n, q;
    cin >> n >> q;
    freq.resize(n);
    vector<int> a(n);
    for (auto &it: a)
        cin >> it;
    compress(a, 0);
    vector<Q> query(q);
    for (int i = 0; i < q; i++)
        cin >> query[i].l >> query[i].r, query[i].i = i;
    sort(query.begin(), query.end(), [&](Q &a, Q &b) {
        return make_pair(a.l / sq, a.r) < make_pair(b.l / sq, b.r);
    });
    vector<int> ans(q);
    int res = 0;
    int l = query[0].l;
    add(a[--l], res);
    int r = l;
    for (auto [L, R, i]: query) {
        L--,R--;
        while (r < R)add(a[++r], res);
        while (l > L)add(a[--l], res);
        while (R < r)erase(a[r--], res);
        while (l < L)erase(a[l++], res);
        ans[i] = res;
    }
    for (auto &ti: ans)cout << ti << endl;
}
