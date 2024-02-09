class Solution {
public:
    int largestAltitude(vector<int>& v) {
    vector<int>pf(v.size() + 1,0);
    pf[1] = v[0];
    for(int i = 1 ; i <= v.size() ; i++){
        pf[i] = pf[i - 1] + v[i-1];
    }
   return *max_element(pf.begin(),pf.end());
}
};