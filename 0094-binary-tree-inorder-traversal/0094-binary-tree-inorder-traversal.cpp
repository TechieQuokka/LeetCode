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
    struct TreeNodeType* table;
    void inorder (struct TreeNode* current) {

        if (current == NULL) return;

        inorder (current->left);
        table.push_back (current->val);
        inorder (current->right);
        return;
    }

public:
    vector<int> inorderTraversal(TreeNode* current) {
        
        if (current == NULL) throw;

        this->table = current;
        inorder (this->table);

        return this->table;
    }
};