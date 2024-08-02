ll max_subarray_sum(vector<ll>&v){
    int n = v.size();
    vector<ll>mx(n);
    mx[0] = max(0LL, v[0]);
    for(int i = 0 ; i < n ; i++)
        mx[i] = max({v[i], v[i] + (i ? mx[i - 1] : 0)});
    ll mx_sum = v[0];
    for(int i = 0 ; i < n ; i++){
        mx_sum = max(mx_sum,  mx[i]);
    }
    return mx_sum;
}
