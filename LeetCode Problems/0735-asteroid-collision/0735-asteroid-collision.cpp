class Solution {
public:
bool left(int n){
    return n < 0;
}
bool right(int n ){
    return n > 0;
}
    vector<int> asteroidCollision(vector<int>& v) {
   stack<int>st;
   vector<int>ans = {};
    for(auto it : v){
        bool flag = 1;
        while(!st.empty() && right(st.top()) && left(it) ){
            if(abs(st.top()) < abs(it))
                {
                    st.pop();
                    continue;
                }else if(abs(st.top()) == abs(it)) st.pop();
                flag = 0 ;
                break;
        }
        if(flag)st.push(it);
    }
   while(!st.empty()){
       ans.push_back(st.top());
       st.pop();
   }
    reverse(ans.begin() , ans.end());
    return ans;
}
};