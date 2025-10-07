class Node {
public:
    int key, val;
    Node* next;
    Node* back;
    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->back = NULL;
    }
};
class LRUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int capacity;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->back = head;
    }

    void deleteNode(Node* node){
        Node* front = node->next;
        Node* prev = node->back;
        front->back = prev;
        prev->next = front;
    }

    void insertNode(Node* node){
        Node* front = head->next;
        node->next = front;
        front->back = node;
        head->next = node;
        node->back = head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            int result = node->val;
            mp.erase(key);
            deleteNode(node);
            insertNode(node);
            mp[key] = head->next;
            return result;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            mp.erase(key);
            deleteNode(node);
        }
        if(mp.size()==capacity){
            mp.erase(tail->back->key);
            deleteNode(tail->back);
        }
        insertNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
