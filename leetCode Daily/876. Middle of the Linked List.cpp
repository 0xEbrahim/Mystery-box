
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
       
        if(head == NULL) return NULL;
        else {
            while(p2 != NULL and p2->next != NULL) {
                p2 = p2->next->next;
                p1 = p1->next;
            }
            return p1;
        }
    }
};
