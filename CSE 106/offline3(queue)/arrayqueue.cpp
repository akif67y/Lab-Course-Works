#include "queue.h"
#include <iostream>
using namespace std;
// Constructor implementation
ArrayQueue::ArrayQueue(int initial_capacity)
{
    // TODO: Initialize data members (data, capacity, front_idx, rear_idx)
    // TODO: Allocate memory for the array with the specified initial capacity
    capacity = initial_capacity;
    front_idx = -1;
    rear_idx = -1;

    data = new int[capacity];
}

// Destructor implementation
ArrayQueue::~ArrayQueue()
{
    // TODO: Free the dynamically allocated memory for the array
    delete []data;
}

// Enqueue implementation (add an item to the rear of the queue)
void ArrayQueue::enqueue(int item)
{
    // TODO: Check if the array is full
    if(size() == capacity){
        resize(capacity * 2);
    }
    rear_idx = (rear_idx + 1) % capacity;
    data[rear_idx] = item;
    if(front_idx == -1){
      front_idx = 0;
    }
    // TODO: If full, resize the array to double its current capacity
    // TODO: Add the new element to the rear of the queue
}

// Dequeue implementation (remove an item from the front of the queue)
int ArrayQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    if(empty()){
        return -1;
    }
    // TODO: Decrement current_size and return the element at the front of the queue
    if(front_idx == rear_idx){
        int t = data[front_idx];
        front_idx = -1;
        rear_idx = -1;
        return t;
    }
    else{
        int t = data[front_idx];
        front_idx = (front_idx + 1) % capacity;
        if(size() * 4 < capacity){
            if(capacity > 2) resize(capacity/2);
        }
        return t;
    }

    // TODO: Update front index
    // TODO: Return the dequeued element
}

// Clear implementation
void ArrayQueue::clear()
{
    // TODO: Reset the queue to be empty (reset capacity, front_idx, rear_idx, data)
    delete[]data;
    data = new int[2];
    front_idx = -1;
    rear_idx = -1;
    capacity = 2;
}

// Size implementation
int ArrayQueue::size() const
{
    if(empty()){return 0;}
    // TODO: Return the number of elements currently in the queue
    int full = 0;
    int i;
    for( i = front_idx; i != rear_idx; i = (i + 1) % capacity){
        full++;
    }
    if(i == rear_idx){full++;}
    return full;
}

// Front implementation
int ArrayQueue::front() const
{
    // TODO: Check if the queue is empty, display error message if it is
    if(empty()){
        return -1;
    }
    return data[front_idx];
    // TODO: Return the element at the front of the queue without removing it
}

// Back implementation (get the element at the back of the queue)
int ArrayQueue::back() const
{
    // TODO: Check if the queue is empty, display error message if it is
    if(empty()){
        return -1;
    }
    return data[rear_idx];
    // TODO: Return the element at the back of the queue without removing it
}

// Empty implementation
bool ArrayQueue::empty() const
{
    // TODO: Return whether the queue is empty (current_size == 0)
    if(front_idx == -1 && rear_idx == -1){
        return true;
    }
    else{
        return false;
    }
}

// Print implementation
string ArrayQueue::toString() const
{

    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
    string s;
    s.push_back('<');
    if(empty()){
        s += '|';
        return s;
    }
    int i;
    for( i = front_idx; i != rear_idx; i = (i + 1) % capacity){
        s += to_string(data[i]);
        s += ", ";
    }
    if(i == rear_idx){
        s += to_string(data[i]);
        s += "|";
    }
    return s;
}

// Resize implementation
void ArrayQueue::resize(int new_capacity)
{    
    // TODO: Create a new array with the new capacity
    // TODO: Copy elements from the old array to the new array
    // TODO: Delete the old array
    // TODO: Update the data pointer and capacity
    // TODO: Update front and rear indices
    if(new_capacity < 2){return;}
    int *temp = new int[new_capacity];
    int newidx = 0;
    int full = size();
    int i;
    for( i = front_idx; i != rear_idx; i = (i + 1) % capacity){
        temp[newidx++] = data[i];
    }
    if(i == rear_idx ){
        temp[newidx++] = data[i];
    }
    delete []data;
    data = temp;
    capacity = new_capacity;
    front_idx = 0;
    rear_idx = full-1;

}

int ArrayQueue::getCapacity() const
{
    // TODO: Return the current capacity of the queue
    return capacity;
}