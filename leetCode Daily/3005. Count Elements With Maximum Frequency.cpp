const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int frq[101];
        int mx = 0;
        for(int i = 0 ; i < nums.size() ; i++){
                frq[nums[i]]++;
                mx = max(mx, frq[nums[i]]);
                }
                int ans = 0;
        for(int i = 0 ; i <= 100 ; i++)
            ans += (frq[i] == mx) * frq[i];
        return ans;
     }
};
