/* Big O of linked list vs vector:
| Operation        | Linked List | Vector   |
| ---------------- | ----------- | -------- |
| Append           | O(1)        | O(1)     |
| Remove last      | O(n)        | O(1)     |
| Prepend          | O(1)        | O(n)     |
| Remove first     | O(1)        | O(n)     |
| Insert           | O(n)        | O(n)     |
| Remove           | O(n)        | O(n)     |
| Look up by index | O(n)        | O(1)     |
| Look up by value | O(n)        | O(n)     |
*/

#include <iostream>
#include "linkedlist.h"

using namespace std;

/**
 * @brief Prints the values of all nodes in the linked list.
 *
 * @return void
 */
void LinkedList::printList()
{
    Node* temp = head;
    while (temp != nullptr) {
        temp = temp->next;
    }
}

/**
 * @brief Gets the value of the head node.
 *
 * @return The value of the head node, or -1 if the list is empty.
 */
int LinkedList::getHead()
{
    return ((head != nullptr) ? head->value : -1);
}

/**
 * @brief Gets the value of the tail node.
 *
 * @return The value of the tail node, or -1 if the list is empty.
 */
int LinkedList::getTail()
{
    return ((tail != nullptr) ? tail->value : -1);
}

/**
 * @brief Gets the length of the linked list.
 *
 * @return The number of nodes in the linked list.
 */
unsigned int LinkedList::getLength()
{
    return length;
}

/**
 * @brief Appends a new node with the given value to the end of the linked list.
 *
 * @param value The value to be added to the new node.
 */
void LinkedList::append(int value)
{
    Node* newNode = new Node(value);
    if (length == 0U) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail       = newNode;
    }
    length++;
}

/**
 * @brief Prepends a new node with the given value to the beginning of the
 * linked list.
 *
 * @param value The value to be added to the new node.
 */
void LinkedList::prepend(int value)
{
    Node* newNode = new Node(value);
    if (length == 0U) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head          = newNode;
    }
    length++;
}

/**
 * @brief Deletes the last node in the linked list.
 *
 * @return void
 */
void LinkedList::deleteLast()
{
    if (length == 0U) {
        return;
    }

    Node* last = nullptr;

    if (length == 1U) {
        last = tail;
        head = nullptr;
        tail = nullptr;
    } else {
        Node* pre = head;
        while (pre->next != tail) {
            pre = pre->next;
        }
        last       = tail;
        tail       = pre;
        tail->next = nullptr;
    }
    delete last;
    length--;
}

void LinkedList::deleteFirst()
{
    if (length == 0U) {
        return;
    }

    Node* temp = head;
    head = head->next;
    if (length == 1U) {
        tail = nullptr;
    }
    delete temp;
    length--;
}

/**
 * @brief Gets the node at the specified index.
 *
 * @param index The index of the node to get.
 * @return The node at the specified index, or nullptr if something went wrong.
 */
Node* LinkedList::getNode(unsigned int index)
{
    if (length == 0U || index >= length) {
        return nullptr;
    }

    Node* temp = head;
    for (unsigned int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

/**
 * @brief Sets the value of the node at the specified index.
 *
 * @param index The index of the node to set.
 * @param value The value to set for the node.
 * @return true if the node was found and set, false otherwise.
 */
bool LinkedList::setNode(unsigned int index, int value)
{
    Node* temp = getNode(index);
    if (temp == nullptr) {
        return false;
    }
    temp->value = value;
    return true;
}

bool LinkedList::insertNode(unsigned int index, int value)
{
    if (index > length) {
        return false;
    } else if (index == 0U) {
        prepend(value);
        return true;
    } else if (index == length) {
        append(value);
        return true;
    } else {
        Node* newNode = new Node(value);
        Node* pre     = getNode(index - 1);
        newNode->next = pre->next;
        pre->next     = newNode;
        length++;
        return true;
    }
}

void LinkedList::deleteNode(unsigned int index)
{
    if (index >= length) {
        return;
    }

    if (index == 0U) {
        return deleteFirst();
    }

    if (index == length - 1U) {
        return deleteLast();
    }

    Node* pre = getNode(index - 1);
    Node* nodeToDelete = pre->next;
    pre->next = nodeToDelete->next;
    delete nodeToDelete;
    length--;
}

void LinkedList::reverse()
{
    if (length <= 1U) {
        return;
    }

    // Swap head and tail
    Node* temp = head;
    head = tail;
    tail = temp;

    // Initialize before and after
    Node* after = temp->next;
    Node* before = nullptr;

    // Loop through list and swap next and before
    for (unsigned int i = 0; i < length; i++) {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
}

