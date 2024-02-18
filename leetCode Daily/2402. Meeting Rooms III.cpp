#define lo long long
class Solution {
public:
    lo mostBooked(int n, vector<vector<int>>& v) {
    priority_queue<pair<lo, lo>, vector<pair<lo, lo>>, greater<>>pq;
    sort(v.begin(),v.end());
    set<lo>s;
    for(lo i = 0 ; i < n ; i++)
        s.insert(i);
    map<lo, lo>mp;
    for(lo i = 0 ; i < v.size() ; i++){
        lo ss = v[i][0] , e = v[i][1];
        while(pq.size()>0 && pq.top().first<=ss){
            lo room=pq.top().second;
            pq.pop();
            s.insert(room);
        }
        if(s.size()==0){
            pair<lo,lo> p=pq.top();
            pq.pop();
            lo dif= e - ss;
            ss=p.first;
            e=ss+dif;
            s.insert(p.second);
        }
        auto it=s.begin();
        mp[*it]++;
        pq.push({e,*it});
        s.erase(*it);
    }
    lo ans=0;
    lo maxi=0;
    for(lo i=0; i < n; i++){
        if(maxi<mp[i]){
            maxi=mp[i];
            ans=i;
        }
    }
    return ans;
}
};
