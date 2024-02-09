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
vector<int>ans;
    void INODRER(TreeNode *root){
        if(!root)
            return;
        INODRER(root -> left);
        ans.push_back(root -> val);
        INODRER(root -> right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
       if(!root)
            return ans;
        INODRER(root);
        return ans;
    }
};
