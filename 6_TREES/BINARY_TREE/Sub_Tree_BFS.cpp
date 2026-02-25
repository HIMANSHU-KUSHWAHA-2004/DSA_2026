#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Check if two trees are identical
bool isidentical(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;     // both null
    if (!t1 || !t2) return false;    // one null

    bool lefter = isidentical(t1->left, t2->left);
    bool righter = isidentical(t1->right, t2->right);

    return lefter && righter && t1->data == t2->data;
}


bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;   

    if (root->data == subRoot->data){
        if(isidentical(root, subRoot));
            return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); 
    /*THIS STEP IS VERY IMPORTANT MEANS HERE WE ARE SHORT CURCUITING THE RECURRSION MEANS IF THE 
    LEFT ONE RETURN THE TRUE MEANS WE HAVE GOT OUR SUBTREE IN THE LEFT SIDE SO THERE IS NO NEED TO 
    CHECK FOR THE RIGHT HAND SIDE SO WE ARE USING THE OR OPERATOR TO SHORT CURCUIT MEANS IF ANY ONE
    GIVE TRUE THEN IT WILL NOT CHECK FOR THE OTHER SIDE*/
}

// Check if subroot is a subtree of root
bool subTree(TreeNode* root, TreeNode* subroot) {
    if (!root) return false;

    queue<TreeNode*> qu;
    qu.push(root);

    while (!qu.empty()) {
        TreeNode* bra = qu.front(); qu.pop();

        if (bra->data == subroot->data) {
            if (isidentical(bra, subroot)) {
                return true;
            }
        }

        if (bra->left) qu.push(bra->left);
        if (bra->right) qu.push(bra->right);
    }

    return false;
}

int main() {
    // Main tree
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

    // Subtree to check
    /*
           5
          /
         10
          \
           13
    */
    TreeNode* subRoot = new TreeNode(5);
    subRoot->left = new TreeNode(10);
    subRoot->left->right = new TreeNode(13);

    if (subTree(root, subRoot))
        cout << "subRoot is a subtree of root" << endl;
    else
        cout << "subRoot is NOT a subtree of root" << endl;

    cout << bool(subTree(root,subRoot)) << endl;
    return 0;
}
