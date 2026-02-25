#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// BFS function to return level order traversal
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode *> qu;
    qu.push(root);
    while (!qu.empty())
    {
        int size = qu.size();
        vector<int> temp;
        while(size--)
        {
            TreeNode *front = qu.front();
            qu.pop();
            temp.push_back(front->val);
            if (front->left)
                qu.push(front->left);
            if (front->right)
                qu.push(front->right);
        }
        ans.push_back(temp);
    }
    return ans;
}

// Utility to print the result
void printLevelOrder(const vector<vector<int>> &levels)
{
    cout << "[\n";
    for (auto &level : levels)
    {
        cout << "  [ ";
        for (int val : level)
            cout << val << " ";
        cout << "]\n";
    }
    cout << "]\n";
}

int main()
{
    /*
               1
            /     \
           2       3
         /   \    /   \
        4     5  6     7
       / \   /       /   \
      8   9 10      11    12
              \
               13
    */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);

    root->right->right->left = new TreeNode(11);
    root->right->right->right = new TreeNode(12);

    root->left->right->left->right = new TreeNode(13);

    vector<vector<int>> result = levelOrder(root);

    cout << "Level Order Traversal of Tree:\n";
    printLevelOrder(result);

    return 0;
}
