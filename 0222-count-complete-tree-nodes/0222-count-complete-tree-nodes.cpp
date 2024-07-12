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
    int CountNodes (struct TreeNode* current) {

        if (current == NULL) return 1;

        int left = this->CountNodes (current->left);
        int right = this->CountNodes (current->right);
        return left + right;
    }

public:
    int countNodes(TreeNode* root) {
        
        if (root == NULL) return 0;

        return this->CountNodes (root) - 1;
    }
};