const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    /*
  When I wrote this, only Allah and I understood what I was doing
  Now, only Allah knows
*/
vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();
    vector<int>ans;
    for(int i = 0 ; i < n ; i++)
            tasks[i].push_back(i);
    sort(tasks.begin(), tasks.end());
    priority_queue<pair<int , int>, vector<pair<int, int>>, greater<>>pq;
    int i = 0;
    long long curTime = tasks[i][0];
    while(!pq.empty() || i < n){
        while(i < n && curTime >= tasks[i][0]){
            pq.push({tasks[i][1], tasks[i][2]});
            i++;
        }
        if(pq.empty()){
            curTime = tasks[i][0];
        }
        else{
            pair<int , int> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
            curTime += p.first;
        }
    }
    return ans;
}
};
