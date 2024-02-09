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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr)
        return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            root = q.front();
            q.pop();
            ans.push_back(root->val);
            if(root->right != nullptr)
                 q.push(root->right);
           if(root->left != nullptr)
                 q.push(root->left);
                   for(int i = 1;i<s;++i){
                TreeNode * temp = q.front();
                q.pop();      
            if(temp->right){q.push(temp->right);}
            if(temp->left){q.push(temp->left);}
            }
        }
        return ans;
    }
};