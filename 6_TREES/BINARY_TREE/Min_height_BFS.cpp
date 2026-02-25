#include <bits\stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
int minDepthBFS(TreeNode *root)
{
    if (!root)
        return 0;
    queue<TreeNode *> BFS;
    BFS.push(root);
    BFS.push(NULL);
    int height = 1;
    while (!BFS.empty())
    {
        TreeNode *current = BFS.front();
        BFS.pop();
        if (current == NULL)
        {
            height++;
            if (!BFS.empty())
                BFS.push(NULL);
        }
        else
        {
            if (current->left == nullptr && current->right == nullptr)
    /*THIS IS IMPORTANT STEP MEANS IF THERE IS THE ANY NODE THAT HAVE BOTH NULL CHILDREN THEN THAT IS THE 
        MINIMUM HEIGHT OF THE TREE EVEN IF THE QUEUE HAS ELEMENTS BUT WE DO NOT HAVE TO CHECK IS AGAIN*/
                return height;

            if (current->left)
                BFS.push(current->left);

            if (current->right)
                BFS.push(current->right);
        }
    }
    return height;
}
int minDepthDFS(TreeNode* root) {
    if (root == nullptr)
        return 0;

    if (root->left == nullptr)
        return minDepthDFS(root->right) + 1;

    if (root->right == nullptr)  
        return minDepthDFS(root->left) + 1;

    return min(minDepthDFS(root->left), minDepthDFS(root->right)) + 1;
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

    TreeNode* root = new TreeNode(1);
    
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
    cout << minDepthBFS(root) << endl;
    cout << minDepthDFS(root) << endl;
}