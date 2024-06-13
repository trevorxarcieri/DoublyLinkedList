// TestingGenericDoublyLinkedCircularList.cpp
// Author: Trevor Arcieri
// Date: 13 June 2024
// Description: Test code for the Generic Doubly-Linked Circular List.

#include "GenericDoublyLinkedCircularList.h"
#include <iostream>
#include <string>

int main() {
    // Create a list of integers
    GenericDoublyLinkedCircularList<int> intList;

    std::cout << "Testing insertions..." << std::endl;
    intList.insertFront(10);
    intList.insertBack(20);
    intList.insertAtIndex(15, 1); // Insert 15 between 10 and 20

    std::cout << "List after insertions (expected: 10, 15, 20): ";
    for (int i = 0; i < intList.getSize(); ++i) {
        std::cout << intList[i] << " "; // Assuming operator[] is implemented
    }
    std::cout << std::endl;

    std::cout << "Testing removals..." << std::endl;
    intList.removeFront();
    intList.removeBack();
    intList.removeAtIndex(0); // Remove the only remaining element, which is 15

    std::cout << "List size after removals (expected: 0): " << intList.getSize() << std::endl;
    std::cout << "Is list empty? (expected: true): " << (intList.isEmpty() ? "Yes" : "No") << std::endl;

    // Create a list of strings to test different data type
    GenericDoublyLinkedCircularList<std::string> stringList;
    stringList.insertBack("Hello");
    stringList.insertBack("World");

    std::cout << "String list contents (expected: Hello, World): ";
    for (int i = 0; i < stringList.getSize(); ++i) {
        std::cout << stringList[i] << " "; // Assuming operator[] is implemented
    }
    std::cout << std::endl;

    return 0;
}

