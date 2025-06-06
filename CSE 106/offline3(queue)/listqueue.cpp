#include "queue.h"
#include <iostream>
using namespace std;

// Constructor implementation
ListQueue::ListQueue()
{
    // TODO: Initialize front_node and rear_node
    front_node = new Node(0, NULL);
    rear_node = front_node;
    // TODO: Initialize current_size to 0
    current_size = 0;
}

// Destructor implementation
ListQueue::~ListQueue()
{
    // TODO: Deallocate all nodes in the linked list
    // TODO: Consider using the clear() method
    clear();
}

// Enqueue implementation (add an item at the rear of the queue)
void ListQueue::enqueue(int item)
{
    // TODO: Create a new node with the given item
    Node *newNode = new Node(item, NULL);
    rear_node->next = newNode;
    rear_node = rear_node->next;
    current_size++;

    // TODO: Link the new node to the rear
    // TODO: Update the rear_node
    // TODO: Increment the current size
}

// Dequeue implementation (remove an item from the front of the queue)
int ListQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    if(empty()){
        return -1;
    }
    Node *tempnode = front_node->next; // tempnode not null
    front_node->next = tempnode->next;
    if(rear_node == tempnode){
        rear_node = front_node;
    }
    int t = tempnode->data;
    delete tempnode;
    current_size--;
    return t;

    // TODO: Store the data from the front node
    // TODO: Update the front pointer to the next node
    // TODO: Update the rear pointer if the queue becomes empty
    // TODO: Delete the old front node
    // TODO: Decrement current_size
    // TODO: Return the stored data
}

// Clear implementation (delete all elements)
void ListQueue::clear()
{
    // TODO: Traverse the linked list and delete each node
    if(front_node->next == NULL){
        return;
    }
    Node *temp = front_node->next;
    while(temp){
        Node *nextone = temp->next;
        delete temp;
        temp = nextone;
    }
    front_node->next =NULL;
    rear_node = front_node;
    current_size = 0;

    // TODO: Reset front and rear pointer
    // TODO: Reset current_size to 0
}

// Size implementation (return the current number of elements)
int ListQueue::size() const
{
    return current_size;
    // TODO: Return the current size (current_size)
}

// Front implementation (get the element at the front of the queue)
int ListQueue::front() const
{
    // TODO: Check if the queue is empty, display error message if it is
    if(empty()){
        return -1;
    }
    return front_node->next->data;
    // TODO: Return the data from the front node without removing it
}

// Back implementation (get the element at the back of the queue)
int ListQueue::back() const
{
    // TODO: Check if the queue is empty, display error message if it is
    if(empty()){
        return -1;
    }
    return rear_node->data;
    // TODO: Return the data from the back node without removing it
}

// Empty implementation (check if the queue is empty)
bool ListQueue::empty() const
{
    // TODO: Return whether front is nullptr
    if(front_node->next == NULL){
        return true;
    }
    else{
        return false;
    }
}

// Print implementation (print elements from front to rear)
string ListQueue::toString() const
{
    string s;
    s.push_back('<');
    if(empty()){
        s.push_back('|');
        return s;
    }
    Node *temp = front_node->next;
    while(temp){
        Node *nextone = temp->next;
        s += to_string(temp->data);
        if(nextone == NULL){
          s += '|';
        }
        else{
            s += ", ";
        }
        temp = nextone;
    }
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
    // TODO: Traverse the linked list from front
}
