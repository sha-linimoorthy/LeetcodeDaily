#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node* convertLL(vector<int>& a)
{
    Node* head = new Node(a[0]);
    Node* mover = head;
    for(int i=1; i<a.size(); i++)
    {
        Node* temp = new Node(a[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

Node* insertElement(Node* head, int pos, int element)
{
    if(head==NULL && pos==1) 
    {
        Node* n = new Node(element);
        return n;
    }
    if(pos==1)
    {
        Node* n = new Node(element, head);
        //n->next = head; 
        return n;
    }
    Node* temp = head;
    Node* prev = NULL;
    int c =0;
    while(temp!=NULL)
    {
        c++;
        if(c==pos-1)
        {
            Node* n = new Node(element, temp->next);
            temp->next = n;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeValue(Node* head, int val, int element)
{
    if(head==NULL) 
    {
        return head;
    }
    if(head->data==val)
    {
        Node* n = new Node(element, head);
        return n;
    }
    Node* temp = head;
    while(temp->next!=NULL)
    {
        c++;
        if(temp->next->data==element)
        {
            Node* n = new Node(element, temp->next);
            temp->next = n;
            break;
        }
        temp = temp->next;
    }
    return head;
}

void print(Node* head)
{
    Node* temp = head;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        int val;
        cin >> val;
        arr[i] = val;
    }

    Node* head = convertLL(arr);
    head = insertElement(head,3,78);
    print(head);
}