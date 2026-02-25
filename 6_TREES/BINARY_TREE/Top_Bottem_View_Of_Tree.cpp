#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    // 🟢 Top View
    vector<int> topView(Node* root) {
        if (root == NULL)
            return {};

        queue<pair<Node*, int>> qu;
        qu.push({root, 0});

        unordered_map<int, int> mpp;
        int mini = 0, maxi = 0;

        while (!qu.empty()) {
            auto current = qu.front();
            qu.pop();

            Node* node = current.first;
            int horizontal = current.second;

            if (mpp.find(horizontal) == mpp.end()) {
                mpp[horizontal] = node->data;
            }

            mini = min(mini, horizontal);
            /*WE CAN ALSO USE THE SIMPLE MAP IF WE USE THE MAP THEN WE DO NOT HAVE TO DO THIS LIKE 
            FINDING THE MIN AND MAX OF THE KEY FOR THE TRAVERSING SINCE THE MAP IS ALREADY SORTED
            BUT MAP TAKE O(logN) TIME AND UMAP TAKE O(1) TIME SO THATS WHY WE ARE USING THE UMAP
            BUT THE UPMAP IS NOT SORTED WE WE HAVE TO TRACK THE MIN AND MAX OF THE KEY SO THAT WE 
            CAN TRAVERSE THE MAP IN THE SORTED ORDER*/
            maxi = max(maxi, horizontal);

            if (node->left)
                qu.push({node->left, horizontal - 1});
            if (node->right)
                qu.push({node->right, horizontal + 1});
        }

        vector<int> result;
        for (int i = mini; i <= maxi; i++) {
            result.push_back(mpp[i]);
        }

        return result;
    }



    vector<int> topview_using_map(Node* root){
        if(root == nullptr)
            return {};
        
        queue<pair<Node*,int>> qu;
        qu.push({root,0});

        map<int,int> mapp;
        
        while(!qu.empty()){
            auto current = qu.front();
            qu.pop();
            Node* Noda = current.first;
            int HD = current.second;

            if(mapp.find(HD) == mapp.end()){
                mapp[HD] = Noda->data;
            }

            if(Noda->left)
                qu.push({Noda->left,HD - 1});
            if(Noda->right)
                qu.push({Noda->right,HD + 1});
        }
        vector<int> result;
        for(auto i : mapp){
            result.push_back(i.second);
        }
        return result;
    }

    // 🔵 Bottom View
    vector<int> bottomView(Node* root) {
        if (root == NULL)
            return {};

        queue<pair<Node*, int>> qu;
        qu.push({root, 0});

        unordered_map<int, int> mpp;
        int mini = 0;
        int maxi = 0;

        while (!qu.empty()) {
            auto current = qu.front();
            qu.pop();

            Node* node = current.first;
            int horizontal = current.second;

            // 🧠 For Bottom View: keep overwriting (deepest node wins)
            mpp[horizontal] = node->data;

            mini = min(mini, horizontal);
            maxi = max(maxi, horizontal);

            if (node->left)
                qu.push({node->left, horizontal - 1});
            if (node->right)
                qu.push({node->right, horizontal + 1});
        }

        vector<int> result;
        for (int i = mini; i <= maxi; i++) {
            result.push_back(mpp[i]);
        }

        return result;
    }
};

int main() {
    /*
            Example Tree:
                   1
                 /   \
                2     3
                 \   / \
                  4 5   6
                     \
                      7

        Top View:    2 1 3 6
        Bottom View: 4 5 7 6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->right = new Node(7);

    Solution sol;

    vector<int> top = sol.topView(root);
    vector<int> top_map = sol.topview_using_map(root);
    vector<int> bottom = sol.bottomView(root);

    cout << "Top View using the Umap: ";
    for (int val : top) cout << val << " ";
    cout << endl;

    cout << "Top View using the Map ";
    for (int val : top_map) cout << val << " ";
    cout << endl;

    cout << "Bottom View: ";
    for (int val : bottom) cout << val << " ";
    cout << endl;

    return 0;
}
