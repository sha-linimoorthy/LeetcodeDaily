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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(ListNode* head : lists)
        {
            while(head!=NULL)
            {
                pq.push(head->val);
                head = head->next;
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(!pq.empty())
        {
            ListNode* newNode = new ListNode(pq.top());
            pq.pop();
            temp->next = newNode;
            temp = temp->next;
        }

        return dummy->next;
    }
};
