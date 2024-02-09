class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";
        for(int i = 0 ; i < s.size() ; i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                clean+=tolower(s[i]);
        }
        string cleaned = clean;
        reverse(clean.begin(), clean.end());
        return clean == cleaned;
    }
};
