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
vector<int>l1,l2;
void dfs1(TreeNode *root){
    if(root == NULL)
        return;
    if(root->right == NULL and root->left == NULL)
        l1.push_back(root->val);    
    dfs1(root->right);
    dfs1(root->left);
}
void dfs2(TreeNode *root){
    if(root == NULL)
        return;
    if(root->right == NULL and root->left == NULL)
        l2.push_back(root->val);    
    dfs2(root->right);
    dfs2(root->left);
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs1(root1);
        dfs2(root2);
        //sort(l1.begin(),l1.end());
       // sort(l2.begin(),l2.end());
        return l1 == l2;
    }
};