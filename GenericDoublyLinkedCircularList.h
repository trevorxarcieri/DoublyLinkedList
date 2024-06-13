// GenericDoublyLinkedCircularList.h
// Author: Trevor Arcieri
// Date: 13 June 2024
// Description: Header file for a generic doubly-linked circular list storing items of type T.

#ifndef GENERIC_DOUBLY_LINKED_CIRCULAR_LIST_H
#define GENERIC_DOUBLY_LINKED_CIRCULAR_LIST_H

#include <iostream>
#include <stdexcept>  // Included for std::out_of_range exception handling

template<typename T>
class GenericDoublyLinkedCircularList {
private:
    struct Node {
        T data;  // Data stored in the node
        Node* prev;  // Pointer to the previous node
        Node* next;  // Pointer to the next node

        // Constructor for creating a new node with given data, previous, and next pointers
        Node(T val, Node* p = nullptr, Node* n = nullptr) : data(val), prev(p), next(n) {}
    };

    Node* head;  // Pointer to the head of the list
    size_t size;  // Size of the list

public:
    // Default constructor initializes an empty list
    GenericDoublyLinkedCircularList() : head(nullptr), size(0) {}

    // Destructor to clear the list upon object destruction
    ~GenericDoublyLinkedCircularList() {
        while (!isEmpty()) {
            removeFront();  // Continuously remove the front until the list is empty
        }
    }

    // Check if the list is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Get the size of the list
    size_t getSize() const {
        return size;
    }

    // Insert a new element at the front of the list
    void insertFront(const T& value) {
        if (isEmpty()) {
            Node* newNode = new Node(value);  // Create a new node
            // If the list is empty, point head to the new node and make it circular
            newNode->next = newNode;
            newNode->prev = newNode; // Prev and next must be assigned outside of constructor because constructor returns pointer to new node after its completion
            head = newNode;
        } else {
            Node* newNode = new Node(value, head->prev, head);  // Create a new node
            // Insert the new node before the current head
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;  // Update head to the new node
        }
        size++;  // Increase the size of the list
    }

    // Insert a new element at the back of the list
    void insertBack(const T& value) {
        if (isEmpty()) {
            insertFront(value);  // If the list is empty, insert at the front
        } else {
            // Create a new node and insert it at the end of the list
            Node* newNode = new Node(value, head->prev, head);
            head->prev->next = newNode;
            head->prev = newNode;
            size++;  // Increase the size of the list
        }
    }

    // Insert a new element at a specified index
    void insertAtIndex(const T& value, int index) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of bounds");  // Validate index range
        }
        if (index == 0) {
            insertFront(value);
        } else if (index == size) {
            insertBack(value);
        } else {
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;  // Navigate to the correct position
            }
            Node* newNode = new Node(value, temp->prev, temp);
            temp->prev->next = newNode;
            temp->prev = newNode;
            size++;  // Insert the new node and update the size
        }
    }

    // Removal at front
    T removeFront() {
        if (isEmpty()) {
            throw std::out_of_range("Attempt to remove from an empty list");
        }
        Node* temp = head;
        T data = temp->data;  // Store data to return
        if (size == 1) {
            head = nullptr;  // If only one node, update head to nullptr
        } else {
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;  // Move head to the next node
        }
        delete temp;
        size--;
        return data;  // Return the removed data
    }

    // Removal at back
    T removeBack() {
        if (isEmpty()) {
            throw std::out_of_range("Attempt to remove from an empty list");
        }
        if (size == 1) {
            return removeFront();  // If only one node, use removeFront
        } else {
            Node* temp = head->prev;
            T data = temp->data;  // Store data to return
            temp->prev->next = head;
            head->prev = temp->prev;
            delete temp;
            size--;
            return data;  // Return the removed data
        }
    }

    // Removal by index
    T removeAtIndex(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        if (index == 0) {
            return removeFront();  // Remove from front if index is 0
        } else if (index == size - 1) {
            return removeBack();  // Remove from back if index is the last
        } else {
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;  // Navigate to the correct position
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            T data = temp->data;  // Store data to return
            delete temp;
            size--;
            return data;  // Return the removed data
        }
    }
};

#endif // GENERIC_DOUBLY_LINKED_CIRCULAR_LIST_H
