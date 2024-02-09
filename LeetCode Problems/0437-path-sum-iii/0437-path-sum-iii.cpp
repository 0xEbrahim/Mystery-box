class Solution {
public:
    int ans = 0 ;
    void solve(TreeNode * root , long long sum){
        if(root == NULL){
            return ;
        }if(root!=NULL){
            if(root->val == sum){
                ans++ ;
            }solve(root->left , sum - root->val) ;
            solve(root->right , sum - root->val) ;
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0 ;
        }
        solve(root , targetSum) ;
        pathSum(root->left , targetSum) ;
        pathSum(root->right , targetSum) ;
        return ans ;
    }
};