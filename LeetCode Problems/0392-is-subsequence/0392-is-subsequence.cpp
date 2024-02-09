class Solution {
public:
    bool isSubsequence(string s, string t) {
    int cnt =0;
    for(int i = 0 ; i < t.size() ; i++)
        if(t[i]==s[cnt])
            cnt++;
    return cnt == s.size();
    }
};