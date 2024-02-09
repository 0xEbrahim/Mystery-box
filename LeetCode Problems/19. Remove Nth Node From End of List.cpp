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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         int sz = 0 ;
    ListNode *root = head;
    while(root){
        sz++;
        root = root->next;
    }
    int sp = sz - n + 1;
    root = head;
    ListNode *prev = new ListNode(0);
    ListNode *nd = prev;
    int xd = 0;
    while(root){
        nd -> next = root;
        xd++;
        if(xd == sp){
            nd -> next = root -> next;
            break;
        }
        root = root -> next;
        nd = nd -> next;
    }
   root = prev -> next;
    return root;
    }
};
