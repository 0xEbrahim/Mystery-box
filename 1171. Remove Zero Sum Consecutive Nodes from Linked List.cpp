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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        for(ListNode *i = dummy; i != NULL; i = i->next){
            int sum = 0;
            for(ListNode *j = i->next; j != NULL ;){
                sum += j->val;
                if(sum == 0){
                    i->next = j->next;
                }
                j = j->next;
            }
        }
        return dummy->next;
    }
};
