class MonoStack{
    stack<int>st;
public:
    MonoStack(){
        while(not st.empty())
            st.pop();
    }
    void prevMin(vector<int>&v, vector<int>&res){
        for(int i = v.size() - 1 ; ~i ; i--){
            if(st.empty()){
                st.push(i);
                continue;
            }
            if(v[i] < v[st.top()]){
                while(not st.empty() and v[i] < v[st.top()]){
                    res[st.top()] = v[i];
                    st.pop();
                }
            }
            st.push(i);
        }
        while(not st.empty()) res[st.top()] = -1, st.pop();
    }

    void nextGreater(vector<int>&v, vector<int>&res){
        for(int i = 0 ; i < v.size() ; i++){
            if(st.empty()) { st.push(i);
                continue;
            }
            if(v[i] > v[st.top()]){
                while(not st.empty() and v[i] > v[st.top()]){
                    res[st.top()] = v[i];
                    st.pop();
                }
            }
            st.push(i);
        }
        while(not st.empty()) res[st.top()] = -1, st.pop();
    }

    void nextMin(vector<int>&v, vector<int>&res){
        for(int i =0 ; i < v.size() ; i++){
            if(st.empty()){
                st.push(i);
                continue;
            }
            if(v[i] < v[st.top()]){
                while(not st.empty() and v[i] < v[st.top()]){
                    res[st.top()] = v[i];
                    st.pop();
                }
            }
            st.push(i);
        }
        while(not st.empty()) res[st.top()] = -1, st.pop();
    }

    void prevMax(vector<int>&v, vector<int>&res){
        for(int i = v.size() - 1 ; ~i ; i--){
            if(st.empty()) { st.push(i);
                continue;
            }
            if(v[i] > v[st.top()]){
                while(not st.empty() and v[i] > v[st.top()]){
                    res[st.top()] = v[i];
                    st.pop();
                }
            }
            st.push(i);
        }
        while(not st.empty()) res[st.top()] = -1, st.pop();
    }
};
