#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    CircularLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void Insert_front()
    {
        int num;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            int x;
            cin >> x;
            Node *new_node = new Node(x);
            if (head == nullptr)
            {
                head = new_node;
                tail = new_node;
                tail->next = head; // first node points to itself
            }
            else
            {
                new_node->next = head;
                head = new_node;
                tail->next = head; // maintain circular link
            }
        }
    }

    void Insert_rear()
    {
        int num;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            int x;
            cin >> x;
            Node *new_node = new Node(x);
            if (head == NULL)
            {
                head = new_node;
                tail = new_node;
                tail->next = head;
            }
            else
            {
                tail->next = new_node;
                tail = new_node;
                tail->next = head;
            }
        }
    }
    void delete_head()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            head = temp->next;
            tail->next = head;
            delete temp;
        }
    }

    void delete_tail()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            Node *old_tail = tail;
            old_tail = tail;
            temp->next = head;
            tail = temp;
            delete old_tail;
            // delete temp;
        }
    }

    void print()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }
};

int main()
{
    CircularLinkedList l1;
    // l1.Insert_front();
    l1.Insert_rear();
    // l1.delete_head();
    l1.delete_tail();

    l1.print();
    return 0;
}
