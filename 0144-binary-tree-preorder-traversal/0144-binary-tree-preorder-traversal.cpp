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
    void Preorder (struct TreeNode* current, vector<int>& buffer) {

        if (current == NULL) return;

        buffer.push_back (current->val);
        Preorder (current->left, buffer);
        Preorder (current->right, buffer);
        return;
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        if (root == NULL) return {};

        vector<int> buffer;
        Preorder (root, buffer);
        return buffer;
    }
};