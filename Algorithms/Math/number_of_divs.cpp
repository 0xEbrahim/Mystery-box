int number_of_factors(int n){
    vector<int>powers;
    for(int i = 2 ; i * i <= n ; i++){
        int cnt = 0;
        while(n % i ==0){
            cnt++;
            n/=i;
        }
        if(cnt != 0)
            powers.push_back(cnt);
    }
    if(n != 1)
        powers.pb(1);
    int count = 1;
    for(long long power : powers)
        count *= (power + 1);
    return count;
}
