class Solution {
public:
  int pivotIndex(vector<int>& num) {
      vector<int>v=num;
    for(int i = 1 ; i < v.size() ; i++){
        v[i] += v[i-1];
    }
    int id = 0;
    bool flag = 0;
    for(int i = 0 ; i < v.size() ; i++){
        int ls = (i==0)?0:v[i - 1];
        int rs = v[v.size()-1]-v[i];
        if(ls == rs){
            flag = true;
            id = i;
            break;
        }
    }
    if(flag){
        return id;
    }else return -1;
}
};