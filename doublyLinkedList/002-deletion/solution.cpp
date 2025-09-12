#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;
    public:
        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->back = NULL;
        }
    public:
        Node(int data, Node* next, Node* back) {
            this->data = data;
            this->next = next;
            this->back = back;
        }
};

Node* convertDLL(vector<int> a)
{
    Node* head = new Node(a[0]);
    Node* mover = head;
    for(int i=1; i<a.size(); i++) {
        Node* temp = new Node(a[i], nullptr, mover);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* deleteHead(Node* head)
{
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp = head;
    head = head->next;
    head->back = NULL;
    temp->next = NULL;
    delete temp;
    return head;
}

Node* deleteTail(Node* head)
{
    if(head==NULL || head->next ==NULL) return NULL;
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->back->next = NULL;
    temp->back = NULL;
    delete temp;
    return head;
}

Node* deleteKthElements(Node* head, int k)
{
    if(head==NULL || head->next==NULL && k==1) return NULL;
    Node* temp = head; int c = 0;
    while(temp->next!=NULL)
    {
        c++;
        if(c==k)
        {
            break;
        }
        temp = temp->next;
    }
    Node* front = temp->next;
    Node* prev = temp->back;
    if(front==NULL && prev==NULL) return NULL;
    else if (front==NULL) return deleteTail(head);
    else if(prev==NULL) return deleteHead(head);
    else{
        front->back = prev;
        prev->next = front;
        temp->back = NULL;
        temp->back = NULL;
        delete temp;
    }
    return head;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        int val;
        cin >> val;
        a[i] = val;
    }
    Node* head = convertDLL(a);
    print(head);
    head = deleteKthElements(head, 2);
    print(head);
    return 0;
}