const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    int minimumLength(string s) {
    vector<pair<char, int>>count;
    int n = s.size();
    int cnt = 1;
    for(int i = 1 ; i < n ; i++){
        if(s[i] == s[i - 1])
            cnt++;
        else{
            count.push_back({s[i - 1], cnt});
            cnt = 1;
        }
    }
    count.push_back({s[n - 1], cnt});
    int l = 0 , r = count.size() - 1;
    while(l <= r){
        if(count[l].first == count[r].first){
            if(l != r)
                count[l].second = 0, count[r].second = 0, l++, r--;
            else{
                if(count[l].second > 1){
                    count[l].second = 0, count[r].second = 0;
                    break;
                }else
                    break;
            }
        }else
            break;
    }
    int ans = 0 ;
    for(int i = 0 ; i < count.size() ; i++){
        ans += count[i].second;
    }
    return ans;
}
};
