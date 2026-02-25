#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int info;
    Node *next;

    Node(int value) : info(value), next(NULL) {}
};

void AddElementAtBack(Node* &start)
{
    int number;
    cout << "Enter the number of nodes :  ";
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        int value;
        cout << "Enter the value of node " << i + 1 << " : ";
        cin >> value;
        Node* newNode = new Node(value);
        if (start == NULL)
        {
            start = newNode;
            /* ITS VERY IMPORTANT LIKE HERE I CAN USE THE NEWNODE-->NEXT = NULL BUT AS YOU CAN SEE THAT THE
               NEWNODE IS ALREADY CREATED WITH NEXT AS NULL SO WE DONT NEED TO DO NEWNODE->NEXT = NULL IN THE NODE CLASS
            */
        }
        else
        {
            Node* mover = start;
            while (mover->next != NULL)
            {
                mover = mover->next;
            }
            mover->next = newNode;
        }
    }
}
void Display(Node* &start)
{
    Node* mover = start;
    /*  THIS MOVER POINTER WE ARE USING TO TRANSVERSE THE LINKLIST MEANS MOVING FROM START TO THE END AS YOU
        CAN SEE FIRST WE POINT THE mover TO THE START POINTER THEN TO THE CHECK FOR THE mover != NULL */
    if(mover == NULL)
        cout << "Underflow";
        
    else{
        while (mover != NULL)
        {
            cout << mover->info << " -> ";
            mover = mover->next;
            //MEANS WE ARE PASSING THE (MOVER) TO (MOVER->NEXT) THIS IS THE NEXT NODE
            /*HERE WE ARE UPDATING THE mover MEANS AS WE KNOW next CONTAIN THE ADDRESS OF THE next  NODE SO
            WE ARE GIVING THE ADDRESS TO THE mover OF THE next NODE */
        }
        cout << "NULL";
    }
}

// void InsertAtKposition(Node* &start){
//     cout << "Enter the element to be added a"
// }

int main()
{
    Node *start = NULL;
    AddElementAtBack(start);
    Display(start);

    
    return 0;
}