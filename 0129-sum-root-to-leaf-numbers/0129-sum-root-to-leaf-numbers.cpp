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
    int DepthFirstSearch (struct TreeNode* current, int number) {

        if (current == NULL) return number;

        number *= 10;
        int value = current->val + number;
        int left = this->DepthFirstSearch (current->left, value);
        int right = this->DepthFirstSearch (current->right, value);

        if (current->left == NULL && current->right == NULL) return value;
        return left + right;
    }

public:
    int sumNumbers(struct TreeNode* root) {
        
        int result = DepthFirstSearch (root, 0);
        return result;
    }
};