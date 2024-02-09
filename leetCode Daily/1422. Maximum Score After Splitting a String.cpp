class Solution {
public:
    int maxScore(string s) {
       vector<int>can0(s.size(),0),can1(s.size(),0);
    for(int i = 0 ; i < s.size() ; i++){
        can0[i] = s[i] =='0';
        can1[s.size() - i - 1] = s[s.size() - i - 1] =='1';
    }
    for(int i = 1 ; i < s.size() ; i++){
        can0[i] += can0[i - 1];
    }
    for(int i = s.size() - 2 ; i >= 0 ; i--){
        can1[i] += can1[i + 1];
    }
    int ans = 0;
    for(int i = 0; i < s.size() ; i++){
         if(i == 0){
            if(s[i] =='0')
                ans = max(ans , can0[i] + can1[i]);
        }
       else if(i == s.size() - 1){
            if(s[i] =='1')
                ans = max(ans , can0[i] + can1[i]);
        }
       else
        ans = max(ans , can0[i] + can1[i]);
    }
    return ans;
    }
};
