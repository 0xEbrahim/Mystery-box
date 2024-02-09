class Solution {
public:
    string addBinary(string a, string b) {
         if(a.size() < b.size()){
     int m = b.size() - a.size();
     string tmp = "";
     for(int i = 0 ; i < m ; i ++){
         tmp+='0';
     }
     tmp +=a;
     a = tmp;
 }else if(b.size() < a.size()){
     int m = a.size() - b.size();
     string tmp = "";
     for(int i = 0 ; i < m ; i ++){
         tmp+='0';
     }
     tmp += b;
     b = tmp;
 }
 string ans(a.size(),'0');
 int carry = 0;
 for(int i = a.size() - 1; i >= 0 ; i--){
     ans[i] = to_string(((a[i]-'0') + (b[i] - '0') + carry)%2)[0];
     carry = (((a[i]-'0') + (b[i] - '0') + carry)/2);
 }
    string ret = "";
    if(carry == 1)
        ret += to_string(carry)[0];
    ret += ans;
    return ret;
    }
};
