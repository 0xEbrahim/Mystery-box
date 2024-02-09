class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
           priority_queue<int>q;
        int cnt = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            q.push(nums[i]);
        }
        int tmp;
        while(q.size() && cnt < k){
            tmp = q.top();
            cnt++;
            q.pop();
        }
        return tmp;
    }
};