class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int>answer(t.size());
        stack<int>st;
        for(int i = t.size()-1 ; i >= 0 ; i--){
             while(!st.empty() && t[i] >= t[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                answer[i] = st.top() - i;
            }
                st.push(i);
        }

        return answer;
    }
};