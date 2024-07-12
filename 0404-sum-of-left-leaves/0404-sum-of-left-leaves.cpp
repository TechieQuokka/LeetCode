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

    int DepthFirstSearch (struct TreeNode* current, bool direction) {

        if (current == NULL) return 0;

        int left = this->DepthFirstSearch (current->left, false);
        int right = this->DepthFirstSearch (current->right, true);

        if (this->IsLeaf (current) && !direction) return current->val;
        return left + right;
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        
        if (root == NULL || this->IsLeaf (root)) return 0;

        return DepthFirstSearch (root, false);
    }
};