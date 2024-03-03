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
    int sz = 0;
    ListNode* prev = new ListNode();
    ListNode*hd = prev;
    int szz = 0;
    ListNode * cur = head;
      while(cur!=NULL){
          szz++;
          cur = cur -> next;
      }
      n = szz - n + 1;
    while(head != NULL){
        sz++;
        if(sz == n){
            prev -> next = head -> next;
            head = NULL;
            delete head;
            break;
        }
        prev -> next = head;
        prev = prev -> next;
        head = head -> next;
    }
    return hd -> next;
}
};
