class Solution {
public:
    long long largestPerimeter(vector<int>& v) {
    sort(v.begin(), v.end());
    long long l = 0 , r = 0 ;
    long long sum = 0;
    long long ans = -1;
    int cnt =0 ;
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] >= sum)
            sum += v[i], cnt++;
        else{
            if(cnt >= 2){
                ans = sum + v[i];
                sum += v[i];
            }else{
                sum += v[i];
            }
        }
    }
    return ans;
}
};
