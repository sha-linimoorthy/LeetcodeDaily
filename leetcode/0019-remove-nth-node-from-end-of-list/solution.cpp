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
        if(head->next==NULL && n==1) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(n--) {
            fast = fast->next;
        }
        if(fast==NULL) {
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return head;
        }
        while(fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* front = slow->next;
        slow->next = front->next;
        delete front;
        return head;
    }
};
