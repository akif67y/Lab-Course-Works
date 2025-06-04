#include "stack.h"
#include <iostream>

// Constructor implementation
ListStack::ListStack() {
    // TODO: Initialize head to nullptr
    head = NULL;
    // TODO: Initialize current_size to 0
    current_size = 0;
}

// Destructor implementation
ListStack::~ListStack() {
    // TODO: Deallocate all nodes in the linked list
    clear();
    // TODO: Consider using the clear() method
}

// Push implementation
void ListStack::push(int item) {
    // TODO: Create a new node with the given item
    Node *newNode = new Node(item, head);
    head = newNode;
    current_size++;
    // TODO: Make the new node point to the current head
    // TODO: Update head to point to the new node
    // TODO: Increment current_size
}

// Pop implementation
int ListStack::pop() {
    if(empty()){
        std::cout <<"Nothing to pop\n";
        return -1;
    }

    // TODO: Check if the stack is empty, display error message if it is
    // TODO: Store the data from the head node
    int temp = head->data;
    Node *temp2 = head;
    head = head->next;
    delete temp2;
    current_size--;
    return temp;

    // TODO: Update head to point to the next node
    // TODO: Delete the old head node
    // TODO: Decrement current_size
    // TODO: Return the stored data
}

// Clear implementation
void ListStack::clear() {
    // TODO: Traverse the linked list, deleting each node
    if(head == NULL){
        return;
    }
    Node*temp ;
    while(head != NULL){
        temp = head->next;
        delete head;
        head = temp;
    }
    head = NULL;
    current_size = 0;

    // TODO: Reset head to nullptr
    // TODO: Reset current_size to 0
}

// Size implementation
int ListStack::size() const {
    // TODO: Return the current size (current_size)
    return current_size;
}

// Top implementation
int ListStack::top() const {
    if(empty()){
        std::cout <<"stack is empty\n";
        return -1;
    }
    // TODO: Check if the stack is empty, display error message if it is
    // TODO: Return the data from the head node without removing it
    return head->data;
}

// Empty implementation
bool ListStack::empty() const {
    // TODO: Return whether head is nullptr
    return head == NULL;
}

// Print implementation
void ListStack::print() const {
    // TODO: Print stack elements from top to bottom in the format: |elem1, elem2, ..., elemN>
    // TODO: Traverse the linked list from head, printing each node's data
    Node *temp = head;
    std::cout <<"|";
    while(temp!= NULL){
        std::cout << temp->data;
        temp = temp->next;
        if(temp == NULL){
            std::cout <<">";
        }
        else{
            std::cout <<", ";
        }
    }
    std::cout <<"\n";
}