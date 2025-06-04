#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "stack.h"

/**
 * A test case structure to hold test metadata and function
 */
struct TestCase {
    std::string name;
    std::function<bool(Stack*)> test_func;
    
    TestCase(const std::string& name, std::function<bool(Stack*)> func)
        : name(name), test_func(func) {}
};

/**
 * Tester class that manages test registration and execution
 */
class StackTester {
private:
    std::vector<TestCase> test_cases;
    std::vector<Stack*> stacks;
    int passed_tests = 0;
    int total_tests = 0;

public:
    /**
     * Add a stack implementation to be tested
     */
    void add_stack(Stack* stack) {
        stacks.push_back(stack);
    }
    
    /**
     * Register a test case
     */
    void register_test(const std::string& name, std::function<bool(Stack*)> test_func) {
        test_cases.push_back(TestCase(name, test_func));
    }
    
    /**
     * Get the implementation type name of a stack
     */
    static std::string get_stack_type(Stack* stack) {
        if (dynamic_cast<ArrayStack*>(stack)) {
            return "ArrayStack";
        } else if (dynamic_cast<ListStack*>(stack)) {
            return "ListStack";
        } else {
            return "Unknown Stack";
        }
    }
    
    /**
     * Run a single test on a specific stack implementation
     */
    bool run_test(const TestCase& test, Stack* stack) {
        std::string stack_type = get_stack_type(stack);
        std::cout << "  " << stack_type << " - " << test.name << ": ";
        
        bool result = test.test_func(stack);
        
        if (result) {
            std::cout << "\033[32mPASSED\033[0m" << std::endl; // Green text
        } else {
            std::cout << "\033[31mFAILED\033[0m" << std::endl; // Red text
        }
        
        return result;
    }
    
    /**
     * Run all registered tests on all registered stack implementations
     */
    bool run_all_tests() {
        // Print header
        std::cout << "===== STACK IMPLEMENTATION TESTS =====" << std::endl;
        
        total_tests = 0;
        passed_tests = 0;
        
        // For each stack implementation
        for (auto stack : stacks) {
            std::string stack_type = get_stack_type(stack);
            std::cout << "\n----- " << stack_type << " Tests -----" << std::endl;
            
            // Run each test case
            for (const auto& test : test_cases) {
                total_tests++;
                if (run_test(test, stack)) {
                    passed_tests++;
                }
            }
        }
        
        // Print test summary
        std::cout << "\n===== TEST SUMMARY =====" << std::endl;
        std::cout << "Total tests: " << total_tests << std::endl;
        std::cout << "Passed: " << passed_tests << std::endl;
        std::cout << "Failed: " << (total_tests - passed_tests) << std::endl;
        
        if (passed_tests == total_tests) {
            std::cout << "All tests PASSED!" << std::endl;
        } else {
            std::cout << "Some tests FAILED!" << std::endl;
        }
        
        return passed_tests == total_tests;
    }
    
    /**
     * Cleanup allocated resources
     */
    void cleanup() {
        for (auto stack : stacks) {
            delete stack;
        }
        stacks.clear();
    }
};

/**
 * Individual test functions for each stack operation
 */

// Test for push method
bool test_push(Stack* stack) {
    stack->clear();
    stack->push(42);
    
    return stack->size() == 1 && stack->top() == 42;
}

// Test for pop method
bool test_pop(Stack* stack) {
    stack->clear();
    stack->push(10);
    stack->push(20);
    
    int popped = stack->pop();
    
    return popped == 20 && stack->size() == 1 && stack->top() == 10;
}

// Test for top method
bool test_top(Stack* stack) {
    stack->clear();
    stack->push(30);
    stack->push(40);
    
    int top_value = stack->top();
    
    // Ensure top doesn't modify the stack
    return top_value == 40 && stack->size() == 2;
}

// TODO: Implement test for the size method
bool test_size(Stack* stack) {


    // TODO: Implement this test case
    stack->clear();
    stack->push(1);
    stack->push(2);
    stack->push(3);
    return stack->size() == 3; // Placeholder
}

// TODO: Implement test for the empty method
bool test_empty(Stack* stack) {
    stack->clear();
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->clear();
    bool ok1 = stack->empty();
    stack->push(1);
    stack->push(2);
    bool ok2 = stack->empty();

    // TODO: Implement this test case
    return ok1 & ~ok2; // Placeholder
}

// TODO: Implement test for the clear method
bool test_clear(Stack* stack) {
    // TODO: Implement this test case
    stack->clear();
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->clear();
    return stack->empty(); // Placeholder
}

// TODO: Implement test for multiple push/pop operations
bool test_multiple_push_pop(Stack* stack) {
    // TODO: Implement this test case to verify LIFO behavior with multiple elements
    bool ok = true;
    stack->clear();
    for(int i = 0; i < 100; i++){
        stack->push(i);
     if((stack->size() != i+1) || (stack->top() != i)){
        return false;
     }
    }
    for(int i = 99; i >= 0; i--){
        int temp = stack->pop();
         if((stack->size() != i) || (temp != i)){
        return false;
     }
    }
    return true; // Placeholder
}

// TODO: Implement test for edge cases (empty stack operations)
bool test_empty_stack_operations(Stack* stack) {
    stack->clear();
    if(stack->pop() != -1){
        return false;
    }
    if(stack->top() != -1){
        return false;
    }
    // TODO: Test behavior when popping or checking top of an empty stack
    return true; // Placeholder
}

// TODO: Implement test for ArrayStack resizing
bool test_array_resizing(Stack* stack) {
    stack->clear();
    for(int i = 0; i < 1000; i++){
        stack->push(i);
          if((stack->size() != i+1) || (stack->top() != i)){
        return false;
     }
    }
    for(int i = 999; i >= 0; i--){
        int temp = stack->pop();
         if((stack->size() != i)){
        return false;
     }
    }

    // TODO: Test if ArrayStack properly resizes when capacity is reached
    return true; // Placeholder
}

// TODO: Implement test for large number of operations
bool test_stress(Stack* stack) {
    // TODO: Test stability with a large number of push and pop operations
        bool ok = true;
    stack->clear();
    for(int i = 0; i < 100; i++){
        if(i == 0 && !stack->empty()){
            return false;
        }
        if(i > 0 && stack->empty()){
            return false;
        }
        stack->push(i);
     if((stack->size() != i+1) || (stack->top() != i)){
        return false;
     }
    }
    for(int i = 99; i >= 0; i--){

        int temp = stack->pop();
         if((stack->size() != i) || (temp != i)){
        return false;
     }
     if(i == 0 && !stack->empty()){
            return false;
        }
        if(i > 0 && stack->empty()){
            return false;
        }
    }
    return true;
    return true; // Placeholder
}

/**
 * Main function
 */
int main() {
    // Create tester instance
    StackTester tester;
    
    // Register stack implementations
    tester.add_stack(new ArrayStack());
    tester.add_stack(new ListStack());
    
    // Register test cases with implemented tests
    tester.register_test("Push Operation", test_push);
    tester.register_test("Pop Operation", test_pop);
    tester.register_test("Top Operation", test_top);
    
    // Register test cases with TODO tests
    tester.register_test("Size Operation", test_size);
    tester.register_test("Empty Operation", test_empty);
    tester.register_test("Clear Operation", test_clear);
    tester.register_test("Multiple Push/Pop", test_multiple_push_pop);
    tester.register_test("Empty Stack Operations", test_empty_stack_operations);
    tester.register_test("Array Resizing", test_array_resizing);
    tester.register_test("Stress Test", test_stress);
    
    // Run all tests
    bool all_passed = tester.run_all_tests();
    
    // Clean up
    tester.cleanup();
    
    return all_passed ? 0 : 1;
}