class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;
        int n = s.size();
        for(int i = 0 ; i < n ; i++)
            ones+=(s[i] == '1');
        string ans(n,'0');
        for(int i = 0 ; i < ones - 1 ; i++)
            ans[i] = '1';
        ans[n - 1] = '1';
        return ans;
    }
};
