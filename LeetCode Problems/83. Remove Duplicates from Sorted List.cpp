/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *root = head;
        if(root == NULL)
            return root;
       
        map<int, bool>vis;
        vis[root -> val] = true;
        while(root){
        ListNode *nxt = root -> next;
            if(nxt == NULL)
                break;
            if(!vis[nxt -> val]){
                vis[nxt -> val] = true;
                root = root -> next;
                }
            else{
                ListNode *tmp = nxt;
                root -> next = nxt -> next;
                tmp = nullptr;
                delete tmp;
            }
        }
        return head;
    }
};
