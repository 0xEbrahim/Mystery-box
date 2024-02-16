class Solution {
public:
static bool sortByFrequency(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}
int findLeastNumOfUniqueInts(vector<int>& v, int k) {
        map<int, int>mp;
        for(int i = 0 ; i < v.size() ; i++)
            mp[v[i]]++;
    vector<pair<int, int>> freqVector(mp.begin(), mp.end());
    sort(freqVector.begin(), freqVector.end(), sortByFrequency);
        int cnt;
        for(auto &i : freqVector){
            while(i.second){
                 if(k == 0)
                break;
                i.second--;
                k--;
            }
        }
        cnt = 0;
        for(auto &i : freqVector)
            if(i.second)
                cnt++;
        return cnt;
    }
};
