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
    while (temp != nullptr)
    {
        cout << temp->value << endl;
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
int LinkedList::getLength()
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

}
