# Delete Elements in Singly Linked List in C++

This C++ program implements a **Singly Linked List** and demonstrates several operations including:

- Creation of a linked list from a vector of integers
- Deletion of:
  - Head node
  - Tail node
  - A node at a specific position
- Printing the contents of the list

## Code Overview

The code includes the following components:

### 1. `Node` Class
Represents a node in the singly linked list. Each node contains:
- An integer `data`
- A pointer to the next node `next`

### 2. Functions

#### `Node* convertLL(vector<int>& a)`
Creates a linked list from a vector of integers.

#### `Node* deleteTail(Node* head)`
Deletes the last node (tail) from the linked list.

#### `Node* deleteHead(Node* head)`
Deletes the first node (head) from the linked list.

#### `Node* deleteElement(Node* head, int k)`
Deletes the node at the k-th position (1-based indexing) from the linked list.

#### `void print(Node* head)`
Prints the elements of the linked list.

### 3. `main()` Function
- Takes an integer `n` as input (size of the list)
- Takes `n` integers as input (the list elements)
- Converts the input into a linked list
- Deletes the 4th node from the list
- Prints the modified list

## Input Format

```bash
n
val1 val2 val3 ... valn
