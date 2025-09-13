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

Node* insertBeforeHead(Node* head, int val){
    Node* n = new Node(val, head, nullptr);
    head->back = n;
    return n;
}

Node* insertBeforeKthElement(Node* head, int val, int k)
{
    if(head==NULL || head->next==NULL || k==1)
    {
        return insertBeforeHead(head, val);
    }
    Node* temp = head; int c = 0;
    while(temp!=NULL)
    {
        c++;
        if(c==k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* n = new Node(val, temp, prev);
    prev->next = n;
    temp->back = n;
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
    //print(head);
    head = insertBeforeKthElement(head, 2, 4);
    print(head);
    return 0;
}