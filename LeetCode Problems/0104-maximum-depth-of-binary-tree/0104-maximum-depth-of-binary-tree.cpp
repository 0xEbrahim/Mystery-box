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
    bool vis[10000+20];
    int id = 0;
    int depth[10000+20] = {0};
   int dfs(TreeNode* nd){
       if(nd == nullptr)
            return 0;
        int hr = dfs(nd->right);
        int hl = dfs(nd->left);
        return max(hr,hl) + 1;
    }

    int maxDepth(TreeNode* root) {
        if(root == nullptr)
        return 0;
      return dfs(root);
    }
};