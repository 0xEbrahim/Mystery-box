 for (int i = 1; i < 1000 + 10; i++) {
        for (int j = 1; j < 1000 + 10; j++) {
            pref[i][j] = pf[i][j] + pref[i - 1][j] +
                              pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
while(q--){
    int hs,ws,hb,wb;
    cin >> hs >> ws >> hb >> wb;
    cout <<  pref[hb - 1][wb - 1] + pref[hs  ][ws ] - pref[hs ][wb - 1] - pref[hb - 1][ws]<<'\n';
 
}
