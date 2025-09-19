class Node {
public:
    string data;
    Node* next;
    Node* back;
    Node(string data, Node* back, Node* next) {
        this->data = data;
        this->back = back;
        this->next = next;
    }
    Node(string data) {
        this->data = data;
        this->back = NULL;
        this->next = NULL;
    }
};

class BrowserHistory {
public:
    Node* curr = NULL;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url, curr, NULL);
        curr->next = newNode;
        curr = curr->next;
    }
    
    string back(int steps) {
        while(steps && curr->back!=NULL) {
            curr = curr->back;
            steps--;
        }
        return curr->data;
    }
    
    string forward(int steps) {
        while(steps && curr->next!=NULL) {
            curr = curr->next;
            steps--;
        }
        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
