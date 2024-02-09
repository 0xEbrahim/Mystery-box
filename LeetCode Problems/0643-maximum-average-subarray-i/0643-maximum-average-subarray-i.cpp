class Solution {
public:
    double findMaxAverage(vector<int>& v, int k) {
        for(int i = 1 ; i < v.size() ; i++){
            v[i]+=v[i-1];
        }
        double x = 0;
        for(int i = 0 ; i + k - 1 < v.size() ; i++){
            if(i)
            x = max(x,(double)((double)v[i+k-1]-(double)v[i-1])/(k * 1.0));
            else
            x = (double)v[i+k-1]/(k * 1.0);
        }
        return x;
    }
};