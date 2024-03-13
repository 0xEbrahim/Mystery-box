class Solution {
public:
    int pivotInteger(int n) {
        int ans = -1;
            int l = 0 , r = n;
            while(l <= r){
                int mid = l + (r - l)/2;
                int sum = (mid * (mid + 1))/2;
                int tot = ((n * (n + 1))/ 2) - sum + mid;
                if(sum < tot)
                    l = mid + 1;
                else if(sum > tot)
                    r = mid - 1;
                else
                {
                    ans = mid;
                    break;
                }
            }
        return ans;
    }
};
