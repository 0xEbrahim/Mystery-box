class Solution {
public:
void moveZeroes(vector<int>& v) {
    vector<int>tmp(v.size(),0);
    int k = 0;
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] != 0){
            tmp[k++] = v[i];
    }
    }
     v=tmp;
    return;
    //return v;
}
};