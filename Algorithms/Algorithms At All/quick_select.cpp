int partition(int l, int r, vector<int>&v){
    int pivot = v[r];
    int i = l - 1;
    for(int j = l ; j < r ; j++){
        if(v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    i++;
    swap(v[i], v[r]);
    return i;
}
int quick_select(int l, int r, vector<int>&v, int k){
    int pivot = partition(l,r, v);
    if((v.size() - pivot) > k){
        return quick_select(pivot + 1, r , v , k);
    }else if((v.size() - pivot) < k){
        return quick_select(l, pivot - 1, v, k);
    }else{
        return v[pivot];
    }
}
