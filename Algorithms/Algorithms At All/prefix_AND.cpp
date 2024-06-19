int n = 100;
    vector<vector<int>>pre_bit(33,vector<int>(n + 5));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 32 ; j++){
            pre_bit[j][i + 1] = pre_bit[j][i] + (((n >> (j)) & 1));
        }
    }
    int q = 1;
    while(q--){
        int l , r;
        cin >> l >> r;
        int ans = 0;
        for(int i = 0 ; i < 32 ; i++){
            if(pre_bit[i][r] - pre_bit[i][l] == l - r + 1)
                ans = set_bit(ans,i);
        }
        cout << ans << endl;
    }
