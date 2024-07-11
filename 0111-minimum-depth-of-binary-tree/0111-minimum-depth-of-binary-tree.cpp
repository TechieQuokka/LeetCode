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
public:
    int minDepth(struct TreeNode* root) {
        
        if (root == NULL) return 0;

        int result = 2147483647;

        stack<pair<struct TreeNode*, int>> buffer;
        buffer.push ({root, 0});

        while (!buffer.empty()) {

            auto current = buffer.top(); buffer.pop();
            auto node = current.first;
            int depth = current.second;

            if (node->left == NULL && node->right == NULL) {

                result = min (result, depth);
            }

            if (node->left != NULL) buffer.push ({node->left, depth + 1});
            if (node->right != NULL) buffer.push ({node->right, depth + 1});
        }

        return result + 1;
    }
};