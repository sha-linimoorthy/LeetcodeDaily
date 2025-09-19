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
    ListNode* findEnd(ListNode* temp) {
        while(temp->next!=NULL) temp= temp->next;
        return temp;
    }
    int len(ListNode* temp) {
        int n = 0;
        while(temp!=NULL) {
            n++;
            temp = temp->next;
        }
        return n;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        int n = len(head);
        if(n==k) return head;
        n = n - (k%n) - 1;
        ListNode* temp = head;
        while(temp!=NULL && n--) {
            temp = temp->next;
        }
        ListNode* tail = temp;
        ListNode* newHead = (temp->next)?(temp->next):head;
        temp = findEnd(newHead);
        temp->next = head;
        tail->next = NULL;
        return newHead;
        
    }
};
