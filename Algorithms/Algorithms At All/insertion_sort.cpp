void insertion_sort(vector<int>&v){
    int n = v.size();
    for(int i = 1 ; i < n ; i++) {
        int j = i - 1;
        int val = v[i];
        while (j >= 0 && v[j] > val) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = val;
    }
}
