#include <gtest/gtest.h>
#include "../../src/linkedlist/linkedlist.h"

TEST(LinkedListTest, SingleNode)
{
    LinkedList* list = new LinkedList(10);
    EXPECT_EQ(10, list->getHead());
    EXPECT_EQ(10, list->getTail());
    EXPECT_EQ(1, list->getLength());
    list->printList();
}
