#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int info)
    {
        data = info;
        next = NULL;
    }
};
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void Creating_from_front()
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
            {
                head = new Node(data);
            }
            else
            {
                Node *newNode = new Node(data);
                newNode->next = head;
                head = newNode;
            }
        }
    }
    void creating_from_back()
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
            {
                head = new Node(data);
            }
            else
            {
                Node *newnode = new Node(data);
                Node *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newnode;
                newnode = temp->next;
            }
        }
    }
    void atFront()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            int data;
            cin >> data;
            Node *newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }
    }
    void atBack()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            int data;
            cin >> data;
            Node *newNode = new Node(data);
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode = NULL;
        }
    }
    void Behind_Node()
    {
        int info;
        cout << "Enter the Node : ";
        cin >> info;
        cout << "Enter the data to be inserted : ";
        int data;
        cin >> data;
        Node *Next = head;
        Node *prev = NULL;
        Node *newNode = new Node(data);
        while (Next->data != info)
        {
            prev = Next;
            Next = Next->next;
        }
        prev->next = newNode;
        newNode->next = Next;
    }
    void Front_Node()
    {
        int node;
        cout << "Enter the Node : ";
        cin >> node;
        cout << "Enter the data to be inserted : ";
        int data;
        cin >> data;
        Node *Next = head;
        Node *prev = NULL;
        Node *newNode = new Node(data);
        while (prev->data != node)
        {
            prev = Next;
            Next = Next->next;
        }
        prev->next = newNode;
        newNode->next = Next;
    }
    void delete_front()
    {
        if (head == NULL)
        {
            cout << "List is empty";
        }
        else
        {
            Node *temp = head;
            head = temp->next;
            delete temp;
        }
    }
    void delete_last()
    {
        if (head == NULL)
        {
            cout << "List is empty";
        }
        else if (head->next == NULL)
        {
            Node *temp = head;
            head = temp->next;
            delete temp;
        }
        else
        {
            Node *temp = head;
            Node *prev = NULL;
            while (temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
    }
    void delete_after_the_node()
    {
        int node;
        cout << "Enter the Node : ";
        cin >> node;
        if (head == NULL)
        {
            cout << "List is empty";
        }
        else if (head->data == node)
        {
            delete_front();
        }
        else
        {
            Node *temp1 = head;
            while (temp1 != NULL && temp1->data != node)
            {
                temp1 = temp1->next;
            }
            if (temp1 == NULL)
            {
                cout << "Node not found";
            }
            else
            {
                Node *temp2 = temp1->next;
                temp1->next = temp2->next;
                delete temp2;
            }
        }
    }
    void delete_before_the_node()
    {
        int node;
        cout << "Enter the Node : ";
        cin >> node;
        if (head == NULL)
        {
            cout << "List is empty";
        }
        else if (head->next == NULL)
        {
            delete_front();
        }
        else
        {
            Node *temp1 = head;
            Node *prev = NULL;
            while (temp1->next != NULL && temp1->next->data != node)
            {
                prev = temp1;
                temp1 = temp1->next;
            }
            prev->next = temp1->next;
            delete temp1;
        }
    }
    void delete_the_Node()
    {
        int node;
        cout << "Enter the Node : ";
        cin >> node;
        if (head == NULL)
        {
            cout << "List is empty";
        }
        else if (head->data == node)
        {
            delete_front();
        }
        else
        {
            Node *temp1 = head;
            Node *prev = NULL;
            while (temp1->data != node && temp1->next != NULL)
            {
                prev = temp1;
                temp1 = temp1->next;
            }
            prev->next = temp1->next;
            delete temp1;
        }
    }
    void searching()
    {
        int node;
        cout << "Enter the Node : ";
        cin >> node;
        Node *temp = head;
        while (temp != NULL && temp->data != node)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Node not found";
        }
        else
        {
            cout << "Node found" << endl;
        }
    }
    int count_nodes()
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void Reverse_LL(){
        Node *current = head;
        Node * prev = NULL;
        Node* Nex = NULL;
        while(current != NULL){
            prev = current->next;
            current->next = Nex;
            Nex = current;
            current = prev;
        }
        head = Nex;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    // Creating list from front
    // LinkedList l1;
    // cout << "Enter for front creation:\n";
    // l1.Creating_from_front();
    // l1.print();

    // New list created separately from back
    LinkedList l2;
    cout << "Enter for back creation:\n";
    l2.creating_from_back();
    // l2.atFront();
    // l2.atBack();
    // l2.Behind_Node();
    // l2.Front_Node();
    l2.print();
    // l2.delete_front();
    // l2.delete_last();
    // l2.delete_after_the_node();
    // l2.delete_before_the_node();
    // l2.delete_the_Node();
    // l2.searching();
    l2.Reverse_LL();
    l2.print();
}
