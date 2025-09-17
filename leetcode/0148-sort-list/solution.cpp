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
    ListNode* merge(ListNode* l, ListNode* r)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(l!=NULL && r!=NULL) 
        {
            if(l->val<=r->val) {
                temp->next= l;
                temp = temp->next;
                l = l->next;
            }
            else{
                temp->next = r;
                temp = temp->next;
                r = r->next;
            }
        }
        if(l) temp->next = l;
        if(r) temp->next = r;
        return dummy->next;
    }
    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};
