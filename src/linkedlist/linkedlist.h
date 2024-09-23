class Node
{
    public:
        int value;
        Node* next;

        Node(int value)
        {
            this->value = value;
            next        = nullptr;
        }
};

class LinkedList
{
    private:
        Node* head;
        Node* tail;
        unsigned int length;

    public:
        LinkedList()
        {
            head   = nullptr;
            tail   = nullptr;
            length = 0;
        }

        LinkedList(int value)
        {
            Node* newNode = new Node(value);
            head          = newNode;
            tail          = newNode;
            length        = 1;
        }

        ~LinkedList()
        {
            Node* temp = head;
            while (head != nullptr) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList();
        int getHead();
        int getTail();
        unsigned int getLength();
        void append(int value);
        void prepend(int value);
        void deleteLast();
        void deleteFirst();
        Node* getNode(unsigned int index);
        bool setNode(unsigned int index, int value);
        bool insertNode(unsigned int index, int value);
        void deleteNode(unsigned int index);
        void reverse();
};
