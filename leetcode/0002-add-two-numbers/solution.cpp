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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(l1!=NULL || l2!=NULL) {
            int sum = carry;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            ListNode* newNode = new ListNode((sum)%10);
            temp->next = newNode;
            temp = temp->next;
            carry = sum/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }

        return dummy->next;
    }
};
