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
void INSERT(ListNode*ans, ListNode*ad){
    ListNode *head = ans ;
    ListNode *prev = NULL;
    while(head){
        prev = head;
        head = head -> next;
    }
    prev -> next = ad;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *ans = nullptr;
    int carry = 0;
    while(l1 && l2){
        int v1 = l1 -> val;
        int v2 = l2 -> val;
        int v3 = v1 + v2 + carry;
        carry = v3 / 10;
        v3 = v3%10;
        ListNode *temp = new ListNode;
        temp -> val = v3;
        if(ans == nullptr) {
            ans = temp;
        }
        else {
            INSERT(ans,temp);
        }
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    if(l1){
        while(l1){
            int v3 = l1 -> val + carry;
            carry = v3 / 10;
            v3 = v3%10;
            ListNode *temp =  new ListNode;
            temp -> val = v3;
            if(ans == nullptr)
                ans = temp;
            else
                INSERT(ans,temp);
            l1 = l1 -> next;
        }
    }
    if(l2){
        while(l2){
            int v3 = l2 -> val + carry;
            carry = v3 / 10;
            v3 = v3%10;
            ListNode *temp = new ListNode;
            temp -> val = v3;
            if(ans == nullptr)
                ans = temp;
            else
                INSERT(ans,temp);

            l2 = l2 -> next;
        }
    }
     if(carry){
        ListNode *temp = new ListNode;
        temp -> val = carry;
        INSERT(ans,temp);
    }
    return ans;
    }
};
