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
    ListNode* doubleIt(ListNode* head) {
        ListNode* cur = head;
        string s = "";
        while(cur){
            s += to_string(cur -> val);
            cur = cur -> next;
        }
        ListNode* curr = new ListNode(0);
        ListNode* ret = curr;
        int idx = 0;
        string h = "";
        int carry = 0;
        for(int i = s.size() - 1 ; ~i ; i--){
            int c = s[i] - '0';
            int mul = 2 * c;
            int to_save = mul%10 + carry;
            h += to_string(to_save);
            carry = mul / 10;
        }
        if(carry)
        h +=  to_string(carry);
        s = h;
        reverse(s.begin(), s.end());
        while(idx < s.size()){
            ListNode* tmp = new ListNode(s[idx++] - '0');
            curr -> next = tmp;
            curr = curr -> next;
        }
        return ret -> next;
    }
};
