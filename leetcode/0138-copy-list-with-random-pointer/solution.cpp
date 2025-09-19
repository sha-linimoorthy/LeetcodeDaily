/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //insert copy in between 
        Node* temp = head;
        while(temp) {
            Node* n = new Node(temp->val);
            n->next = temp->next;
            temp->next = n;
            temp = temp->next->next;
        }
        temp = head;
        //random ptrs
        while(temp) {
            Node* n = temp->next;
            if(temp->random) n->random = temp->random->next;
            else n->random = NULL;
            temp = temp->next->next;
        }
        //extract copy
        temp = head;
        Node* dummy = new Node(-1);
        Node* dt = dummy;
        while(temp) {
            dt->next = temp->next;
            dt = dt->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;

    }
};
