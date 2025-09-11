# Linked List Search in C++

## Description

This program demonstrates how to:

- Create a singly linked list from a vector of integers.
- Search for a target value in the linked list.
- Return the index of the first occurrence of the target, or -1 if not found.

## Features

- Uses a custom `Node` class to represent linked list nodes.
- Includes two constructors for the `Node` class to allow flexible initialization.
- Contains helper functions:
  - `convertLL`: Converts a `vector<int>` into a linked list.
  - `searchLL`: Searches for a given value in the linked list and returns its index.

## How to Use

1. **Compile the code** using a C++ compiler. For example:
   ```bash
   g++ -o linked_list_search program.cpp
   ```
2. **Run the executable:**

   ./linked_list_search