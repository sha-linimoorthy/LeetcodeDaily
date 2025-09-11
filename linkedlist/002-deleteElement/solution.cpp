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

Node* deleteTail(Node* head)
{
    if(head==nullptr || head->next==nullptr) return nullptr;
    Node* temp = head;
    while(temp->next->next!=nullptr)
    {
        temp = temp->next;
    }
    delete (temp->next);
    temp->next = nullptr;
    return head;
}

Node* deleteHead(Node* head)
{
    if(head==nullptr) return head;
    if(head->next==nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteElement(Node* head, int k)
{
    if(head==NULL) return head;
    int c = 0;
    Node* temp = head;
    Node* prev = NULL;
    if(k==1)
    {
        head = head->next;
        delete temp;
        return head;
    }
    
    while(temp!=NULL)
    {
        c++;
        if(c==k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
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
    head = deleteElement(head,4);
    print(head);
}