// GenericDoublyLinkedCircularList.h
// Author: Trevor Arcieri
// Date: 13 June 2024
// Description: Header file for a generic doubly-linked circular list storing items of type T.

#ifndef GENERIC_DOUBLY_LINKED_CIRCULAR_LIST_H
#define GENERIC_DOUBLY_LINKED_CIRCULAR_LIST_H

#include <iostream>

template<typename T>
class GenericDoublyLinkedCircularList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(T val, Node* p = nullptr, Node* n = nullptr)
            : data(val), prev(p), next(n) {}
    };

    Node* head;
    size_t size;

public:
    // Default constructor
    GenericDoublyLinkedCircularList() : head(nullptr), size(0) {}

    // Destructor
    ~GenericDoublyLinkedCircularList() {
        while (!isEmpty()) {
            removeFront();
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

    // Insert at front
    void insertFront(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Insert at back
    void insertBack(const T& value) {
        if (isEmpty()) {
            insertFront(value);
        } else {
            Node* newNode = new Node(value, head->prev, head);
            head->prev->next = newNode;
            head->prev = newNode;
            size++;
        }
    }

    // Insert by index
    void insertAtIndex(const T& value, int index) {
        if (index < 0 || index > size) {
            std::cerr << "Index out of bounds" << std::endl;
            return;
        }
        if (index == 0) {
            insertFront(value);
        } else if (index == size) {
            insertBack(value);
        } else {
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            Node* newNode = new Node(value, temp->prev, temp);
            temp->prev->next = newNode;
            temp->prev = newNode;
            size++;
        }
    }

    // Removal at front
    void removeFront() {
        if (!isEmpty()) {
            Node* temp = head;
            if (size == 1) {
                head = nullptr;
            } else {
                head->prev->next = head->next;
                head->next->prev = head->prev;
                head = head->next;
            }
            delete temp;
            size--;
        }
    }

    // Removal at back
    void removeBack() {
        if (!isEmpty()) {
            if (size == 1) {
                removeFront();
            } else {
                Node* temp = head->prev;
                temp->prev->next = head;
                head->prev = temp->prev;
                delete temp;
                size--;
            }
        }
    }

    // Removal by index
    void removeAtIndex(int index) {
        if (index < 0 || index >= size) {
            std::cerr << "Index out of bounds" << std::endl;
            return;
        }
        if (index == 0) {
            removeFront();
        } else if (index == size - 1) {
            removeBack();
        } else {
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            size--;
        }
    }
};

#endif // GENERIC_DOUBLY_LINKED_CIRCULAR_LIST_H

