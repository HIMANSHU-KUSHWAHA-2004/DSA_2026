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

string str = "";
string serialize(Node* root){
    if(root == nullptr)
        return "";
    
    queue<Node*> qu;
    qu.push(root);
    while(!qu.empty()){
        auto curr = qu.front();
        qu.pop();
        if(curr == nullptr)
            str.append("@,");
        else
            str.append(to_string(curr->data) + ",");
        if(curr != nullptr){
            qu.push(curr->left);
            qu.push(curr->right);
        }
    }
    return str;
}

Node* deserialize(string s){
    vector<string> boka;
    string temp = "";
    for(auto i : s){
        if(i == ','){
            boka.push_back(temp);
            temp = "";
        }
        else{
            temp += i;
        }
    }
    boka.push_back(temp);


    if(boka[0] == "@")
        return nullptr;
    
    queue<Node*> qu;
    Node* root = new Node(stoi(boka[0]));
    qu.push(root);
    int i = 1;
    while(!qu.empty() && i < boka.size()){
        auto curr = qu.front();
        qu.pop();
        if(boka[i] != "@"){
            curr->left = new Node(stoi(boka[i]));
            qu.push(curr->left);
        }
        i++;

        if(i < boka.size() && boka[i] != "@"){
            curr->right = new Node(stoi(boka[i]));
            qu.push(curr->right);
        }
        i++;
    }
    return root;
}
void inorder(Node* root){
    if(root== nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}
int main() {
    /*
            50
           /  \
         30    60
        / \    / \
      5   20  45  70
                  / \
                 65  80
    */

    Node *root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(60);

    root->left->left = new Node(5);
    root->left->right = new Node(35);

    root->right->left = new Node(55);
    root->right->right = new Node(70);

    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);
    string str = serialize(root);
    cout << str << endl;
    Node * bhola = deserialize(str);
    inorder(bhola);
    return 0;
}
