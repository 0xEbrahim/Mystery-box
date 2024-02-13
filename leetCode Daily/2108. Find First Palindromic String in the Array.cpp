class Solution {
public:
    string firstPalindrome(vector<string>& v) {
        string ret = "";
        for(int i = 0 ; i < v.size() ;i++){
            string x = v[i];
            reverse(x.begin(), x.end());
            if(x == v[i]){
                ret = v[i];
                break;
            }
        }
        return ret;
    }
};
