class Solution {
public:
    string reverseWords(string s) {
    vector<string>ans;
    int l = 0 , r = 1 ;
    for(int i = 0 ; i <s.size() ; i ++){
        if(s[i] != ' '){
         l = i;
         r = i;
         break;
        }
    }
    int n = s.size();
    for(int i = s.size() -1 ; i >= 0 ; i--){
        if(s[i] != ' ')
        {
            n = i;
            break;
        }
    }
    string tmp = "";
    while(r  <=  n){
        if(s[r]!=' '){
            tmp+=s[r];
            r++;
        }else if(s[r] == ' '){
            ans.push_back(tmp);
            tmp="";
            for(int i = r ; i < s.size() ; i++){
                if(s[i] != ' '){
                    l = i;
                    r = i;
                    break;
                }
            }
        }
    }
    ans.push_back(tmp);
    string y = "";
    std::reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        y += ans[i];
        if(i != ans.size()-1){ y += " "; }
    }
    return y;
}
};