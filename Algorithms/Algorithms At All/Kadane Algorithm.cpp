int KadaneAlgorithms(vector<int>&v){
 
    int mx_Sum = v[0];
 
    for(int i = 1 ; i< v.size() ; i++){
 
        v[i] = max(v[i], v[i] + v[i - 1]);
        mx_Sum = max(mx_Sum , v[i]);
}
    return mx_Sum;
}
