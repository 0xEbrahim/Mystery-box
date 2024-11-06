void merge(int l, int r, vector<int>&v){
    int mid = l + (r - l) / 2;
    int i = l, j = mid + 1;
    vector<int>tmp;
    while(i <= mid && j <= r){
        if(v[i] <= v[j]){
            tmp.push_back(v[i++]);
        }else{
            tmp.push_back(v[j++]);
        }
    }
    while(i <= mid){
        tmp.push_back(v[i++]);
    }
    while(j <= r){
        tmp.push_back(v[j++]);
    }
    int p = 0;
    for(int k = l ; k <= r ; k++){
        v[k] = tmp[p++];
    }
}
void merge_sort(int l, int r, vector<int>&v){
    if(l >= r)
        return;
    int mid = l + (r - l) / 2;
    merge_sort(l, mid, v);
    merge_sort(mid + 1, r, v);
    return merge(l, r, v);
}
