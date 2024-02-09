class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
     if(n == 0)return true;
    if(v.size() == 1 && v[0] == 0 && n == 1){
        return true;
    }else if(v.size() == 1 && v[0] == 1 && n > 0){
        return false;
    }
  int l = 0 , r = 0 ;
    int ans = 0;
    bool flag = 0;
    while(r < v.size() ){
        if(v[r]==1 && !l && !flag){
            ans = r - l ;
            flag = true;
           // if(!(ans&1))ans--;
            n-=((ans)/2);
            l = r++;
        }else if(v[r]==0) {
            r++;
        }else if(v[l] == 1 && v[r] == 1){
            ans = r - l - 1;
            if(!(ans&1))
                ans--;
            n-=((ans)/2);
            l = r++;
        }else if(v[l] == 1 && v[r] == 0){
            r++;
        }
    }
   if(flag){ ans = r - l - 1; }
    else ans = r-l + 1;
    n-=((ans)/2);
    return n<=0;

    }
};