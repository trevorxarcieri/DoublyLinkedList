// TestingGenericDoublyLinkedCircularList.cpp
// Author: Trevor Arcieri
// Date: 13 June 2024
// Description: Test code for the Generic Doubly-Linked Circular List.

#include "GenericDoublyLinkedCircularList.h"
#include <iostream>
#include <string>

int main() {
    // Creating a list to store integer values
    GenericDoublyLinkedCircularList<int> intList;

    std::cout << "Testing insertions...\n";
    intList.insertFront(10);  // Insert 10 at the front of the list
    intList.insertBack(20);   // Insert 20 at the back of the list
    intList.insertAtIndex(15, 1);  // Insert 15 at index 1 (between 10 and 20)

    // Display the list contents after insertions
    std::cout << "Inserted 10 at the front, 15 in the middle, 20 at the back.\n";
    
    std::cout << "Testing removals...\n";
    if (!intList.isEmpty()) {
        std::cout << "Removed from back: " << intList.removeBack() << " (expected 20)\n";  // Remove and display the back item
    }
    if (!intList.isEmpty()) {
        std::cout << "Removed at index 1: " << intList.removeAtIndex(1) << " (expected 15)\n";  // Remove and display the middle item
    }
    if (!intList.isEmpty()) {
        std::cout << "Removed from front: " << intList.removeFront() << " (expected 10)\n";  // Remove and display the front item
    }

    // Check if the list is empty after removals
    std::cout << "List size after removals (expected: 0): " << intList.getSize() << std::endl;
    std::cout << "Is list empty? (expected: Yes): " << (intList.isEmpty() ? "Yes" : "No") << std::endl;

    // Create and test a list of strings to demonstrate template functionality with different data types
    GenericDoublyLinkedCircularList<std::string> stringList;
    stringList.insertBack("Hello");  // Insert "Hello" at the back
    stringList.insertBack("World");  // Insert "World" at the back

    // Display and remove string list contents using removal
    std::cout << "String list contents and removals:\n";
    if (!stringList.isEmpty()) {
        std::cout << "Removed: " << stringList.removeFront() << " (expected: Hello)\n";
    }
    if (!stringList.isEmpty()) {
        std::cout << "Removed: " << stringList.removeFront() << " (expected: World)\n";
    }

    return 0;
}
