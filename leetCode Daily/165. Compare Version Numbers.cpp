class Solution {
public:
   int compareVersion(string version1, string version2) {
    vector<int>v1,v2;
    
    int n = version1.size();
    int m = version2.size();
    string tmp = "";
    for(int i = 0 ; i < n ; i++){
        if(version1[i] != '.')
            tmp += version1[i];
        else{
            
            v1.push_back(stoll(tmp));
            tmp = "";
        }
    }
    v1.push_back(stoll(tmp));
    tmp = "";
    for(int i = 0 ; i < m ; i++){
        if(version2[i] != '.')
            tmp += version2[i];
        else{
          
            v2.push_back(stoll(tmp));
            tmp = "";
        }
    }
    v2.push_back(stoll(tmp));
    tmp = "";
    while(v1.size() < v2.size()){
        v1.push_back(0);
    }
    while(v2.size() < v1.size()){
        m++;
        v2.push_back(0);
    }
    bool neg = false;
    bool pos = false;
    for(int i = 0 ; i < max(v1.size() , v2.size()) ; i++){
        if(v1[i] < v2[i]){
            neg = true;
            break;
        }
        else if(v1[i] > v2[i]){
            pos = true;
            break;
        }
    }
    int ans = 0;
    if(neg)
        ans  = -1;
    else if(pos)
        ans = 1;
    else if(v1 == v2)
        ans =  0;
    return ans;
}
};
