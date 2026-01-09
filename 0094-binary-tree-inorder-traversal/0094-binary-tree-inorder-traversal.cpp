/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> table;

    void inorder(TreeNode* current) {
        if (current == nullptr) return;

        inorder(current->left);
        table.push_back(current->val);
        inorder(current->right);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return table;
    }
};
