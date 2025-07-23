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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || head->next==nullptr || left==right)
        {
            return head;
        }
        ListNode *x = head;
        ListNode *xn = new ListNode();
        ListNode *xp = nullptr;
     
        for(int i=0;i<left-1;i++)
        {
            xp = x;
            x = x->next;
        }
        ListNode * a = x;
        ListNode * b = xp;
        xp = nullptr;
        for(int i=0;i<(right-left)+1;i++)
        {
            xn = x->next;
            x->next = xp;
            xp = x;
            x = xn;
        }
        a->next = x;
        if(b!=nullptr) b->next = xp;
        else head = xp;

        return head;
        
    }
};
