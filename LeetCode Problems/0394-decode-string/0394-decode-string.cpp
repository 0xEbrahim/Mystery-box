class Solution {
public:
    string decodeString(string s) {
        stack<string>str;
        stack<int>count;
        string ans="";
        int num=0;
        for (int i=0;i<s.size();i++){
           if (s[i]>='0' && s[i]<='9'){ 
               num=10*num+s[i]-'0';
           }
           else if (s[i]=='[') {//reset
                str.push(ans);
                ans="";
                count.push(num);
                num=0;
           }
           else if(s[i]==']'){ //add the num times to the ans
               string temp=ans;
               ans=str.top();
               str.pop();
               int times=count.top();
               count.pop();
               while (times--){
                   ans+=temp;
               }
           }
           else { // for char 
               ans+=s[i];
           }

        }
        return ans;
    }
};