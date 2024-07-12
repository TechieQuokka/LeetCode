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

    void DepthFirstSearch (struct TreeNode* current, string number, vector<string>& outResult) {

        if (current == NULL) return;

        string value = number == "" ? to_string(current->val) : format ("{}->{}", number, to_string(current->val));
        this->DepthFirstSearch (current->left, value, outResult);
        this->DepthFirstSearch (current->right, value, outResult);

        if (this->IsLeaf (current)) {

            outResult.push_back (value);
            return;
        }
        return;
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        if (root == NULL) return {};

        vector<string> result;
        DepthFirstSearch (root, "", result);
        return result;
    }
};