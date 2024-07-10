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

    int value;
    bool direction;
    int depth;
};

class Solution {
private:
    void traversal (struct TreeNode* current, bool direction, int depth, vector<struct DataType>& result) {

        if (current == NULL) return;

        result.push_back ({current->val, direction, depth});
        traversal (current->left, false, depth + 1, result);
        traversal (current->right, true, depth + 1, result);
        return;
    }

public:
    bool isSameTree(struct TreeNode* left, struct TreeNode* right) {
        
        if (left == NULL && right == NULL) return true;

        vector<struct DataType> leftBuffer, rightBuffer;
        traversal (left, false, 0, leftBuffer);
        traversal (right, false, 0, rightBuffer);

        if (leftBuffer.size() != rightBuffer.size()) return false;

        int length = leftBuffer.size();
        for (int index = 0; index < length; index++) {

            if (leftBuffer[index].value != rightBuffer[index].value) return false;
            if (leftBuffer[index].direction != rightBuffer[index].direction) return false;
            if (leftBuffer[index].depth != rightBuffer[index].depth) return false;
        }

        return true;
    }
};