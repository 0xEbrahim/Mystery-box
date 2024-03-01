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
    map<TreeNode* , int>depth;
    int sum(TreeNode *node){
        if(node == NULL)
            return 0;
        return node -> val + sum(node -> right) + sum(node -> left);
    }
    void dfs(TreeNode * node){
        if(node == NULL)
            return;
        dfs(node -> left);
        dfs(node -> right);
        if(node -> left != NULL && node -> right != NULL){
        depth[node] = depth[node -> right] + depth[node -> left] + 1;
        }
       else if(node -> left == NULL && node -> right == NULL)
            depth[node] = 1;
        else if(node -> left == NULL)
            depth[node] = depth[node -> right] + 1;
        else if(node -> right == NULL)
            depth[node] = depth[node -> left] + 1;
    }
    int averageOfSubtree(TreeNode* root) {
        int counter = 0;
        dfs(root);
        for(auto &[a, b] : depth){
            if(a -> val == (int)sum(a)/(b))
                counter++;
        }
    return counter;
    }
};
