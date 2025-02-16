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
    bool IsLeaf (struct TreeNode* current) {

        return current->left == NULL && current->right == NULL;
    }

    int DepthFirstSearch (struct TreeNode* current, int number) {

        if (current == NULL) return 0;

        int value = current->val + number * 10;
        int left = this->DepthFirstSearch (current->left, value);
        int right = this->DepthFirstSearch (current->right, value);

        if (this->IsLeaf (current)) return value;
        return left + right;
    }

public:
    int sumNumbers(struct TreeNode* root) {
        
        if (root == NULL) throw;
        return DepthFirstSearch (root, 0);
    }
};