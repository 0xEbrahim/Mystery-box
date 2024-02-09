class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) {
            return "";
        }

        int len = s.length();
        std::vector<std::vector<bool>> dp(len, std::vector<bool>(len, false));

        int start = 0;
        int end = 0;
        int max = 0;

        for (int i = 0; i < len; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                }

                if (dp[j][i] && max < i - j + 1) {
                    max = i - j + 1;
                    start = j;
                    end = i;
                }
            }
        }

        return s.substr(start, max);
    }
};
