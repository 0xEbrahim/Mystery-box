class Solution {
public:
    int longestPalindrome(string s) {
     map<char , int>freq;
    int n = s.size();
    int maxOdd = 0 ;
    for(int i = 0 ; i < n ; i++)
        freq[s[i]]++;
    for(auto &[a , b] : freq){
        if(b & 1)
        maxOdd = max(maxOdd, b);
    }
    int even = 0 , odd = 0;
    bool flag = true;
    for(auto &[a , b] : freq){
       if(!(b & 1))
           even += b;
       else{
           if(flag && b == maxOdd)
               odd += b, flag = false;
           else
               odd += b - 1;
       }
    }
   return odd + even;
    }
};
