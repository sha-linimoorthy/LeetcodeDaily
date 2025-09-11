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

int searchLL(Node* head, int target)
{
    int counter = 0;
    Node* temp = head;
    while(temp)
    {
        if(temp->data==target)
        {
            return counter;
        }
        temp = temp->next;
        counter++;
    }
    return -1;
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
    cout << searchLL(head, 30);
}