class Solution {
public:
   int myAtoi(string s) {
    string ans = "";
    bool can = false;
    int pos = 0 , neg = 0;
    int n = s.size();
    for(int i = 0 ; i < n ; i++){
        if(s[i] == ' ' && can)
            break;
        if(s[i] == ' ')
            continue;
        if(isdigit(s[i])){
            ans += s[i], can = true;

        } else if(s[i] != '-' && s[i] != '+')
            break;
        else if(s[i] == '-' && can) {
            break;
        }else if(s[i] == '-') {
            if (i + 1 < n) {
                if (isdigit(s[i + 1])) {
                    ans += s[i], neg++;
                }else
                    break;
            }
        }
        else if(s[i] == '+' && can) {
                break;
        }else if(s[i] == '+')
                if(i + 1 < n){
                    if(isdigit(s[i + 1])){
                        pos++;
                    }else
                        break;
                }

    }
    string st = "";
    bool g = false;
    for(int i = 0 ; i < ans.size() ; i++){
        if(ans[i] =='-'){
            st+=ans[i];
            continue;
        }
        if(ans[i] != '0')
            g = true;
        if(g)
            st+=ans[i];
    }
    ans = st;
    if((pos && neg) || (pos > 1) || (neg > 1) || !can)
        ans = "";
    if(ans.size() == 1 && ans[0] == '-')
        ans = "";
    int res = 0;
    if(ans.size() > 10 && ans[0] != '-')
        res = INT_MAX;
    else if(ans.size() > 11 && ans[0] == '-')
        res = INT_MIN;
    else if(ans.size() == 10 && ans[0] != '-'){
        if(stoll(ans) < INT_MAX)
            res = stoll(ans);
        else
            res = INT_MAX;
    }else if (ans.size() == 11 && ans[0] == '-'){
        if(stoll(ans) < INT_MIN)
            res = INT_MIN;
        else
            res = stoll(ans);
    }
    if(ans.empty())
        ans = "0";
    return res == 0 ? stoll(ans) : res;
}
};
