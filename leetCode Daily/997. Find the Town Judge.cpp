
class Solution { public: int findJudge(int N, vector<vector<int>>& v) { 	
map<int, int >mp,tr;
int n = v.size() ;
if(N==1)return 1;
for(int i = 0 ; i < n ; i++) 
mp[v[i][1]]++,tr[v[i][0]]++;
int ans=-1;
for(auto &[a, b]:mp) 
if(b==N-1 && !tr[a]) 
ans=a;
return ans;

	 		 } 
              }; 
