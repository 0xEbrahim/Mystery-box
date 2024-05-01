class Solution {
public:
    string reversePrefix(string word, char ch) {
        string s;
        int idx = 0;
        for(idx ; idx < word.size(); idx++){
            s+=word[idx];
            if(word[idx] == ch)
                break;
        }
        if(idx != word.size())
        reverse(s.begin(), s.end());
        for(int i = idx + 1 ; i < word.size() ; i++)
            s += word[i];
            return s;
    }
};
