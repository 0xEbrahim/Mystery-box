class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int freq[29] = {0};
        int n = words.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < words[i].size() ; j++){
                freq[words[i][j] - 'a']++;
            }
        }
        bool x = true;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < words[i].size() ; j++){
               x &= !(freq[words[i][j] - 'a']%n);
            }
        }
        return x;
    }
};
