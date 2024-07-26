void Still_Up() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>>freq(n + 1, vector<int>(26,0));
    for(int i = 0 ; i < n ; i++){
        freq[i + 1][s[i] - 'a']++;
    }
    for(int i = 1 ; i < n ; i++) {
        for(int j = 0 ; j < 26 ; j++){
            freq[i][j] += freq[i - 1][j];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l , r;
        cin >> l >> r;
        char x;
        cin >> x;
        int pos = x - 'a';
        cout << abs(freq[r][pos] - freq[l - 1][pos])<<endl;
    }
}
