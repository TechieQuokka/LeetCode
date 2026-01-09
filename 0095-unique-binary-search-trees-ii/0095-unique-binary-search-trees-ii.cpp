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
    vector<TreeNode*> generateTrees(int number) {

        return generateTrees (1, number);
    }

private:
    vector<struct TreeNode*> generateTrees (int start, int end) {

        if (start > end) return vector<struct TreeNode*>{nullptr};

        vector<struct TreeNode*> result;

        for (int root = start; root <= end; root++) {

            auto leftTrees = generateTrees (start, root - 1);
            auto rightTrees = generateTrees (root + 1, end);

            for (auto& leftTree : leftTrees) {
                for (auto& rightTree : rightTrees) {

                    auto newTree = new struct TreeNode(root);
                    newTree->left = leftTree;
                    newTree->right = rightTree;
                    result.push_back (newTree);
                }
            }
        }
        return result;
    }
};