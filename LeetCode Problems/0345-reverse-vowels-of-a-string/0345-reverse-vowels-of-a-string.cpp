class Solution {
public:
string reverseVowels(string s) {
set<char>v = {'a','e','i','o','u'};
vector<char>vol;
for(int i = 0 ; i < s.size() ; i++){
    if(v.count(tolower(s[i])))
        vol.push_back(s[i]);
}
int id = 0;
    std::reverse(vol.begin(), vol.end());
for(int i = 0 ; i < s.size() ; i++){
    if(v.count(tolower(s[i])))
        s[i] = vol[id++];
}
return s;
}
};