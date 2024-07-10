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

struct DataType {

    struct TreeNode* node;
    int depth;
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if (root == NULL) return 0;
        
        queue<struct DataType> buffer;
        buffer.push ({root, 0});

        int depth = 0;
        while (!buffer.empty()) {

            auto current = buffer.front(); buffer.pop();
            if (current.node == NULL) continue;

            depth = max (depth, current.depth);
            buffer.push ({current.node->left, current.depth + 1});
            buffer.push ({current.node->right, current.depth + 1});
        }

        return depth + 1;
    }
};