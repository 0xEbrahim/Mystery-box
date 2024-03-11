class Solution {
public:
    string customSortString(string order, string s) {
        int freq[27] = {0};
        for(int i = 0 ; i < s.size() ; i++)
            freq[s[i] - 'a']++;
            string ans = "";
        for(int i = 0 ; i < order.size() ; i++){
            if(freq[order[i] - 'a']){
                while(freq[order[i] - 'a']){
                        freq[order[i] - 'a']--;
                        ans.push_back(order[i]);
                }

            }
        }
        for(int i = 0 ; i < 27 ; i++)
        if(freq[i])
            while(freq[i]){
                freq[i]--;
                ans.push_back((char)(i + 'a'));
            }
            return ans;
    }
};
