#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int info;
    Node *next;

    Node(int val) : info(val), next(NULL) {}
    /*THIS IS A CONSTRUCTOR WHICH TAKES INPUT INFO*/
};

void AddElementToEmptyLinklistFromFront(Node *&start)
{
    int numberOfNodes;
    cout << "Enter the number of the nodes : ";
    cin >> numberOfNodes;
    for (int i = 0; i < numberOfNodes; i++)
    {
        int val;
        cout << "Enter the value of the node: ";
        cin >> val;
        Node *newnode = new Node(val);
        newnode->next = start; /*THIS MEANS FILLLING newnode->next(newnode KA next)
        WITH THE CURRENT START OF THE LINKLISTmatlab jo bhi pehele start mai tha ab vo newnode mai
        aa jayegga*/
        start = newnode;
    }
}
void DisplayAllNodesOfLinklist(Node *&start)
{
    if (start == NULL)
        cout << "The linklist is empty" << endl;
    else
    {
        Node* temp = start;
        while (temp != NULL)
        {
            cout << temp->info << " --> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}
int main()
{
    Node *start = NULL;
    AddElementToEmptyLinklistFromFront(start);
    DisplayAllNodesOfLinklist(start);
    return 0;
}