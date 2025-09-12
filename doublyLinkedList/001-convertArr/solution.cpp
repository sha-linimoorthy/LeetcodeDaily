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
    return 0;
}