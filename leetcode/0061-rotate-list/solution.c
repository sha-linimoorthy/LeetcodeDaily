/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *tail = head;
    struct ListNode *ptr = head;
    int count =0;
    int size = 1;
    if(head==NULL) return head;
    if(head->next==NULL) return head;
    if(head->next->next==NULL){
        if(k%2!=0){
            head->next->next = head;
            head = head->next;
            head->next->next=NULL;
        }
        return head;
    }
    while(tail->next!=NULL){
        tail = tail->next;
        size++;
    }
    printf("%d",size);
    if(k%size==0) return head;
    tail->next=head;
    while(count!=(size-(k%size)-1)){
        ptr = ptr->next;
        count++;
    }

    head=ptr->next;
    ptr->next=NULL;
    return head;
    
}
