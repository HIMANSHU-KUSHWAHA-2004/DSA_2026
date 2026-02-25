#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtPosition(int pos, int val) {
        if (pos <= 0) {
            cout << "Invalid position\n";
            return;
        }
        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; i++)
            temp = temp->next;
        if (!temp) {
            cout << "Position out of range\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int pos) {
        if (!head || pos <= 0) {
            cout << "Invalid position or empty list\n";
            return;
        }
        if (pos == 1) {
            deleteAtBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; temp->next && i < pos - 1; i++)
            temp = temp->next;
        if (!temp->next) {
            cout << "Position out of range\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void sort() {
        if (!head || !head->next) return;
        for (Node* i = head; i->next; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                if (i->data > j->data)
                    swap(i->data, j->data);
            }
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, val, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Search\n";
        cout << "8. Reverse List\n";
        cout << "9. Sort List\n";
        cout << "10. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 3:
            cout << "Enter position and value: ";
            cin >> pos >> val;
            list.insertAtPosition(pos, val);
            break;
        case 4:
            list.deleteAtBeginning();
            break;
        case 5:
            list.deleteAtEnd();
            break;
        case 6:
            cout << "Enter position to delete: ";
            cin >> pos;
            list.deleteAtPosition(pos);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> val;
            if (list.search(val))
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;
        case 8:
            list.reverse();
            cout << "List reversed\n";
            break;
        case 9:
            list.sort();
            cout << "List sorted\n";
            break;
        case 10:
            list.display();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}
