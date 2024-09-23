#include <gtest/gtest.h>
#include "../../src/linkedlist/linkedlist.h"

TEST(LinkedListTests, CreateEmptyList)
{
    // Arrange
    LinkedList* list = new LinkedList();

    // Act & Assert
    EXPECT_EQ(-1, list->getHead());
    EXPECT_EQ(-1, list->getTail());
    EXPECT_EQ(0, list->getLength());
}

TEST(LinkedListTests, CreateListWithSingleNode)
{
    // Arrange
    LinkedList* list = new LinkedList(10);

    // Act & Assert
    EXPECT_EQ(10, list->getHead());
    EXPECT_EQ(10, list->getTail());
    EXPECT_EQ(1, list->getLength());
}

TEST(appendTests, AppendNodeToEmptyList)
{
    // Arrange
    LinkedList* list = new LinkedList();

    // Act
    list->append(10);

    // Assert
    EXPECT_EQ(10, list->getTail());
    EXPECT_EQ(1, list->getLength());
}

TEST(appendTests, AppendNodeToExistingList)
{
    // Arrange
    LinkedList* list = new LinkedList(10);

    // Act
    list->append(20);

    // Assert
    EXPECT_EQ(20, list->getTail());
    EXPECT_EQ(2, list->getLength());
}

TEST(prependTests, PrependNodeToEmptyList)
{
    // Arrange
    LinkedList* list = new LinkedList();

    // Act
    list->prepend(10);

    // Assert
    EXPECT_EQ(10, list->getHead());
    EXPECT_EQ(10, list->getTail());
    EXPECT_EQ(1, list->getLength());
}

TEST(prependTests, PrependNodeToExistingList)
{
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    list->prepend(40);

    // Assert
    EXPECT_EQ(40, list->getHead());
    EXPECT_EQ(30, list->getTail());
}

TEST(deleteLastTests, DeleteLastNodeFromEmptyList)
{
    // Arrange
    LinkedList* list = new LinkedList();

    // Act
    list->deleteLast();

    // Assert
    EXPECT_EQ(-1, list->getHead());
    EXPECT_EQ(-1, list->getTail());
    EXPECT_EQ(0, list->getLength());
}

TEST(deleteLastTests, DeleteLastNodeFromListWithSingleNode)
{
    // Arrange
    LinkedList* list = new LinkedList(10);

    // Act
    list->deleteLast();

    // Assert
    EXPECT_EQ(-1, list->getHead());
    EXPECT_EQ(-1, list->getTail());
    EXPECT_EQ(0, list->getLength());
}

TEST(deleteLastTests, DeleteLastNodeFromListWithMultipleNodes)
{
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);
    list->append(40);

    // Act
    list->deleteLast();

    // Assert
    EXPECT_EQ(10, list->getHead());
    EXPECT_EQ(30, list->getTail());
    EXPECT_EQ(3, list->getLength());
}

TEST(deleteFirstTests, DeleteFirstNodeFromEmptyList)
{
    // Arrange
    LinkedList* list = new LinkedList();

    // Act
    list->deleteFirst();

    // Assert
    EXPECT_EQ(-1, list->getHead());
    EXPECT_EQ(-1, list->getTail());
    EXPECT_EQ(0, list->getLength());
}

TEST(deleteFirstTests, DeleteFirstNodeFromListWithSingleNode)
{
    // Arrange
    LinkedList* list = new LinkedList(10);

    // Act
    list->deleteFirst();

    // Assert
    EXPECT_EQ(-1, list->getHead());
    EXPECT_EQ(-1, list->getTail());
    EXPECT_EQ(0, list->getLength());
}

TEST(deleteFirstTests, DeleteFirstNodeFromListWithMultipleNodes)
{
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    list->deleteFirst();

    // Assert
    EXPECT_EQ(20, list->getHead());
    EXPECT_EQ(30, list->getTail());
    EXPECT_EQ(2, list->getLength());
}

TEST(getNodeTests, GetNodeFromEmptyList)
{
    // Arrange
    LinkedList* list = new LinkedList();

    // Act
    Node* node = list->getNode(0);

    // Assert
    EXPECT_EQ(nullptr, node);
}

TEST(getNodeTests, GetNodeWhenIndexIsOutOfRange)
{
    // Arrange
    LinkedList* list = new LinkedList(10);

    // Act
    Node* node = list->getNode(5);

    // Assert
    EXPECT_EQ(nullptr, node);
}

TEST(getNodeTests, GetNodeFromListWithSingleNode)
{
    // Arrange
    LinkedList* list = new LinkedList(10);

    // Act
    Node* node = list->getNode(0);

    // Assert
    EXPECT_EQ(10, node->value);
}

TEST(getNodeTests, GetNodeFromListWithMultipleNodes)
{
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    Node* node = list->getNode(1);

    // Assert
    EXPECT_EQ(20, node->value);
}

TEST(setNodeTests, SetNodeToEmptyList)
{
    // Arrange
    LinkedList* list = new LinkedList();

    // Act
    bool result = list->setNode(0, 10);

    // Assert
    EXPECT_EQ(false, result);
}

TEST(setNodeTests, SetNodeWhenIndexIsOutOfRange)
{
    // Arrange
    LinkedList* list = new LinkedList(10);

    // Act
    bool result = list->setNode(5, 20);

    // Assert
    EXPECT_EQ(false, result);
}

TEST(setNodeTests, SetNodeWhenIndexIsInRange)
{
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    bool result = list->setNode(1, 15);

    // Assert
    EXPECT_EQ(true, result);
    EXPECT_EQ(15, list->getNode(1)->value);
}

TEST(insertTests, InsertNodeWhenIndexIsOutOfRange)
{
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    bool result = list->insertNode(5, 15);

    // Assert
    EXPECT_EQ(false, result);
}

TEST(insertTests, InsertNodeWhenIndexIsZero)
{
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    bool result = list->insertNode(0, 15);

    // Assert
    EXPECT_EQ(true, result);
    EXPECT_EQ(15, list->getHead());
}

TEST(insertTests, InsertNodeWhenIndexIsEqualToLength)
{
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    bool result = list->insertNode(3, 15);

    // Assert
    EXPECT_EQ(true, result);
    EXPECT_EQ(15, list->getTail());
}

TEST(insertTests, InsertNodeWhenIndexIsInRange)
{
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    bool result = list->insertNode(1, 15);

    // Assert
    EXPECT_EQ(true, result);
    EXPECT_EQ(15, list->getNode(1)->value);
}

TEST(deleteNodeTests, DeleteNodeWhenIndexIsOutOfRange)
{
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    list->deleteNode(5);

    // Assert
    EXPECT_EQ(10, list->getHead());
    EXPECT_EQ(30, list->getTail());
    EXPECT_EQ(3, list->getLength());
}

TEST(deleteNodeTests, DeleteNodeWhenIndexIsZero)
{
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    list->deleteNode(0);

    // Assert
    EXPECT_EQ(20, list->getHead());
    EXPECT_EQ(30, list->getTail());
    EXPECT_EQ(2, list->getLength());
}

TEST(deleteNodeTests, DeleteNodeWhenIndexIsEqualToLength)
{
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    list->deleteNode(2);

    // Assert
    EXPECT_EQ(10, list->getHead());
    EXPECT_EQ(20, list->getTail());
    EXPECT_EQ(2, list->getLength());
}

TEST(deleteNodeTests, DeleteNodeWhenIndexIsInRange)
{
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);
    list->append(40);

    // Act
    list->deleteNode(2);

    // Assert
    EXPECT_EQ(10, list->getHead());
    EXPECT_EQ(40, list->getTail());
    EXPECT_EQ(3, list->getLength());
}

TEST(reverseTests, ReverseEmptyList)
{
    // Arrange
    LinkedList* list = new LinkedList();

    // Act
    list->reverse();

    // Assert
    EXPECT_EQ(-1, list->getHead());
    EXPECT_EQ(-1, list->getTail());
    EXPECT_EQ(0, list->getLength());
}

TEST(reverseTests, ReverseListWithSingleNode)
{
    // Arrange
    LinkedList* list = new LinkedList(10);

    // Act
    list->reverse();

    // Assert
    EXPECT_EQ(10, list->getHead());
    EXPECT_EQ(10, list->getTail());
    EXPECT_EQ(1, list->getLength());
}

TEST(reverseTests, ReverseListWithMultipleNodes)
{
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);
    list->append(40);

    // Act
    list->reverse();

    // Assert
    EXPECT_EQ(40, list->getHead());
    EXPECT_EQ(30, list->getNode(1)->value);
    EXPECT_EQ(20, list->getNode(2)->value);
    EXPECT_EQ(10, list->getTail());
    EXPECT_EQ(4, list->getLength());
}
