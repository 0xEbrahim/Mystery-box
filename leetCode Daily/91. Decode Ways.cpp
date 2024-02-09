#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
vector<int>dp;
int n ;
string v;
int DP(int i){
    if(i == n)
        return 1;
    int &ret = dp[i];
    if(~ret)
        return ret;
    if(v[i] == '0')
        return ret = 0;
    int op1 = DP(i + 1);
    if(i + 1 < n &&(v[i] == '1' || (v[i] == '2' && v[i + 1] <= '6')))
        op1+=DP(i + 2);
    return ret = op1;
    
}
   int numDecodings(string s) {
       if(s[0] == '0')
       return 0;
    n = s.size();
    dp.assign(n + 1 , -1);
    v =s;
    return DP(0);
}
};
