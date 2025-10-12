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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode* temp = head;
        int n = 1;
        while(temp->next!=NULL){
            n++;
            temp = temp->next;
        }
        n = n - k%n-1;
        temp->next = head;
        temp = head;
        while(n--){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
