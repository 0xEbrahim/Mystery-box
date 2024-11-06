int partition(int l, int r, vector<int>&v){
    int pivot = v[r];
    int i = l - 1;
    for(int j = l ;j < r ; j++){
        if(v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    i++;
    swap(v[i], v[r]);
    return i;
}
void quick_sort(int l, int r, vector<int>&v){
    if(r <= l)
        return;
    int pivot = partition(l, r, v);
    quick_sort(l,pivot - 1,v);
    quick_sort(pivot + 1,r,v);
}
