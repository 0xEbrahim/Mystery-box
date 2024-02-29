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
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        bool isOddEven = true;
        map<int, vector<int>>lvl;
        lvl[0].push_back(root -> val);
        if(root -> val % 2 == 0)
        return false;
        while(not q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(node -> left != NULL){
                    q.push({node -> left , level + 1});
                    lvl[level + 1].push_back(node -> left -> val);
                }
                if(node -> right != NULL){
                    q.push({node -> right , level + 1});
                    lvl[level + 1].push_back(node -> right -> val);
                }
         }
         for(auto &[a, b] : lvl){
             if(a == 0 && b.size())
                continue;
            if(a & 1){
                isOddEven &= (b[0] % 2 == 0);
                for(int i = 1 ; i < b.size() ; i++ ){
                    isOddEven &= (b[i] < b[i - 1] && b[i] % 2 == 0);
                    if(!isOddEven)
                        return false;
                        }
            }else{
                isOddEven &= (b[0] % 2 == 1);
                for(int i = 1 ; i < b.size() ; i++){
                    isOddEven &= (b[i] > b[i - 1] && b[i] % 2 == 1);
                        if(!isOddEven)
                        return false;
                    }
            }
         }
        return isOddEven;
    }
};
