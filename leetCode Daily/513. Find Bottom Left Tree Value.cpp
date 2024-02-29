class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode*ans = root;
        while(!q.empty()) {
            ans=q.front(); 
            q.pop();
            if (ans->right != NULL) 
                q.push(ans->right);
            if(ans->left != NULL)
             q.push(ans->left);
        }
        return ans->val;
        
    }
};
