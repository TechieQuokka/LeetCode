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

enum DirectionType { LEFT = 1, RIGHT = 2 };

struct DataType {

    struct TreeNode* current, * parent;
    int depth;
    enum DirectionType direction;
};

class Solution {
private:
    bool Find (struct TreeNode* current, int target, int depth, int targetDepth) {

        if (current == NULL) return false;

        if (current->val == target) {
            if (depth != targetDepth) return false;
            return true;
        }
        if (current->val > target) return Find (current->left, target, depth + 1, targetDepth);
        else return Find (current->right, target, depth + 1, targetDepth);
    }

public:
    bool isValidBST(struct TreeNode* root) {

        if (root == NULL) return false;

        struct TreeNode temp = { 2147483647 };

        queue<struct DataType> buffer;
        buffer.push ({root, &temp, 0, LEFT});
        while (!buffer.empty()) {

            auto data = buffer.front(); buffer.pop();
            auto current = data.current;
            auto parent = data.parent;

            cout << current->val << " : " << parent->val << "\n";
            
            bool result = Find (root, current->val, 0, data.depth);
            if (result == false || current->val == parent->val && parent->val != 2147483647) return false;
            else if (data.direction == LEFT  && current->val > parent->val) return false;
            else if (data.direction == RIGHT && current->val < parent->val) return false;

            if (current->left != NULL) buffer.push ({current->left, current, data.depth + 1, LEFT});
            if (current->right != NULL) buffer.push ({current->right, current, data.depth + 1, RIGHT});
        }
        return true;
    }
};