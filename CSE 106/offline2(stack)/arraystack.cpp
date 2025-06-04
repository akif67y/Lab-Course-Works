#include "stack.h"
#include <iostream>

// Constructor implementation
ArrayStack::ArrayStack(int initial_capacity) {
    // TODO: Initialize data members (data, capacity, current_size)
    capacity = initial_capacity;
    current_size = 0;
    // TODO: Allocate memory for the array with the specified initial capacity
    data = new int[capacity];
}

// Destructor implementation
ArrayStack::~ArrayStack() {
    // TODO: Free the dynamically allocated memory for the array
    delete data;
}

// Push implementation
void ArrayStack::push(int item) {
    if(current_size>= capacity/2){
        resize(capacity * 2);
    }
    data[current_size++] = item;
    // TODO: Check if the array is 50% full (current_size >= capacity/2)
    // TODO: If 50% full, resize the array to double its current capacity
    // TODO: Add the new element to the top of the stack and increment current_size
}

// Pop implementation
int ArrayStack::pop() {
    // TODO: Check if the stack is empty, display error message if it is
    if(empty()){
        std::cerr <<"No element to pop\n";
        return -1;
    }
    int ans = data[current_size-1];
    current_size--;
 
    if(current_size *4 < capacity){
        resize(capacity/2);
    }
    return ans;

    // TODO: Decrement current_size and return the element at the top of the stack
    // TODO: If the array is less than 25% full, resize it to half its current capacity
    // TODO: Return the popped element
}

// Clear implementation
void ArrayStack::clear() {
    // TODO: Reset the stack to be empty (set current_size to 0)
    current_size = 0;
    // TODO: No need to free memory, just logically clear the stack
}

// Size implementation
int ArrayStack::size() const {
    return current_size;
    // TODO: Return the number of elements currently in the stack (current_size)
}

// Top implementation
int ArrayStack::top() const {
    // TODO: Check if the stack is empty, display error message if it is
    if(empty()){
          std::cerr <<"No element to show\n";
        return -1;
    }
    return data[current_size-1];
    // TODO: Return the element at the top of the stack without removing it
}

// Empty implementation
bool ArrayStack::empty() const {
    // TODO: Return whether the stack is empty (current_size == 0)
    return current_size == 0;
}

// Print implementation
void ArrayStack::print() const {
    // TODO: Print stack elements from top to bottom in the format: |elem1, elem2, ..., elemN>
     std::cout <<"|";
    for(int i = current_size-1; i >= 0; i--){
        std::cout << data[i] ;
        if(i == 0){
            std::cout <<">";
        }
        else{
            std::cout <<", ";
        }
    }
    std::cout <<"\n";

}

// Resize implementation
void ArrayStack::resize(int new_capacity) {
    // TODO: Create a new array with the new capacity
    
    int *temp = new int[new_capacity];
    for(int i = 0; i < current_size; i++){
        temp[i] = data[i];
    }
    delete data;
    data = temp;
    capacity = new_capacity;
    // TODO: Copy elements from the old array to the new array
    // TODO: Delete the old array
    // TODO: Update the data pointer and capacity
}