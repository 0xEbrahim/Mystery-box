/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<long long>levels(10000 + 21,0);
        queue<TreeNode*>q;
        q.push(root);
        int lvl ; 
        int max_sum_so_far = INT_MIN;
        int dep = 0;
        while(!q.empty()){
            dep++;
            int curSum = 0;
            int n = q.size();
            while(n--){
                TreeNode* u = q.front();
                q.pop();
                curSum += u->val;
                if(u->right != NULL) q.push(u->right);
                if(u->left != NULL) q.push(u->left);
            }
            if(max_sum_so_far < curSum){
                max_sum_so_far = curSum;
                lvl = dep;
            }
        }
        
        return lvl;
    }
};