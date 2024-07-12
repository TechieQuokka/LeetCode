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
        void Postorder (struct TreeNode* current, vector<int>& buffer) {

            if (current == NULL) return;

            Postorder (current->left, buffer);
            Postorder (current->right, buffer);
            buffer.push_back (current->val);
            return;
        }


public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        if (root == NULL) return {};

        vector<int> buffer;
        Postorder (root, buffer);
        return buffer;
    }
};