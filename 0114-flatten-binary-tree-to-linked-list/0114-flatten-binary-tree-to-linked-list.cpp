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
    void Preorder (struct TreeNode* current, vector<struct TreeNode*>& buffer) {

        if (current == NULL) return;

        buffer.push_back (current);
        Preorder (current->left, buffer);
        Preorder (current->right, buffer);
        return;
    }

public:
    void flatten(struct TreeNode* root) {

        if (root == NULL) return;
        
        vector<struct TreeNode*> buffer;
        this->Preorder (root, buffer);

        for (auto& pivot : buffer) {

            pivot->left = pivot->right = NULL;
        }

        struct TreeNode* successor = buffer.back(); buffer.pop_back();
        struct TreeNode* predecessor = NULL;

        while (!buffer.empty()) {

            predecessor = buffer.back(); buffer.pop_back();
            predecessor->right = successor;
            successor = predecessor;
        }

        return;
    }
};