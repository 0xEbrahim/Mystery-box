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
const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    vector<TreeNode*>ans;
    void dfs(TreeNode* &node, set<int>&del){
        if(node == NULL)
            return;
            TreeNode*tmp = node;
            dfs(node -> left, del);
            dfs(node -> right, del);
        if(del.count(node -> val)){
        if(node -> left != NULL){
           ans.push_back(node -> left);
        }
        if(node -> right != NULL){
        ans.push_back(node -> right);
        }
        node = NULL;
        delete node;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root == NULL)
        return ans;
        set<int>s(to_delete.begin(), to_delete.end());
        dfs(root, s);
       if(root)
       ans.push_back(root);
        return ans;
    }
};
