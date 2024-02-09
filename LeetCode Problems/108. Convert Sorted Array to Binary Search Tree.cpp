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
TreeNode *build(vector<int>&v , int l, int r){
    if(l > r)
        return NULL;
    int mid= l + (r - l)/2;
    TreeNode*nd = new TreeNode(v[mid]);
    nd -> left = build(v, l, mid - 1);
    nd -> right = build(v, mid + 1 , r);
    return nd;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return build(nums, 0 , nums.size() - 1);
}
};
