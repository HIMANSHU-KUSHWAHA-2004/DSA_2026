#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

int mini = INT_MAX;
pair<int,int> pt;
void Min_Differnce_bw_Nodes(Node *root,Node* &prev){

    if(root == NULL)
        return ;
    
    Min_Differnce_bw_Nodes(root->left,prev);
    if(prev != NULL){
        int boka = root->data - prev->data;
        if(mini > boka){
            mini = boka;
            pt = {root->data,prev->data};
        }
    }
    prev = root;
    Min_Differnce_bw_Nodes(root->right,prev);
}

int main()
{
   Node* root = new Node(10);
root->left = new Node(5);
root->right = new Node(15);

root->left->left = new Node(2);
root->left->right = new Node(6);   // close to 5

root->right->left = new Node(14);  // close to 15
root->right->right = new Node(20);
//         10
//       /    \
//      5      15
//     / \    /  \
//    2   6  14  20
Node* prev = nullptr;
Min_Differnce_bw_Nodes(root,prev);
cout << pt.first << " " << pt.second<< " " << mini << endl;


    return 0;
}