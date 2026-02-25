#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qp, qq;
        qp.push(p);
        qq.push(q);

        while (!qp.empty() && !qq.empty()) {
            TreeNode* n1 = qp.front(); qp.pop();
            TreeNode* n2 = qq.front(); qq.pop();

            // Both null → continue
            if (!n1 && !n2) continue;

            // One null → not same
            if (!n1 || !n2) return false;

            // Values differ → not same
            if (n1->val != n2->val) return false;

            // Push children
            qp.push(n1->left);
            qp.push(n1->right);
            qq.push(n2->left);
            qq.push(n2->right);
        }

        return qp.empty() && qq.empty();
    }
};

int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution sol;
    if (sol.isSameTree(p, q))
        cout << "Trees are identical" << endl;
    else
        cout << "Trees are NOT identical" << endl;

    // Example with difference
    q->right->val = 4; 
    if (sol.isSameTree(p, q))
        cout << "Trees are identical" << endl;
    else
        cout << "Trees are NOT identical" << endl;

    return 0;
}
