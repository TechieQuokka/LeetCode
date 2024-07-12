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
    void DepthFirstSearch (struct TreeNode* current, map<int, int>& buffer) {

        if (current == NULL) return;

        this->DepthFirstSearch (current->left, buffer);
        this->DepthFirstSearch (current->right, buffer);

        int value = current->val;
        if (buffer.find (value) == buffer.end()) buffer[value] = 1;
        else buffer[value]++;
        return;
    }

public:
    vector<int> findMode(TreeNode* root) {
        
        if (root == NULL) return {};

        map<int, int> buffer;
        this->DepthFirstSearch (root, buffer);

        vector<int> result;

        int maximumKey = -2147483648, maximumValue = -2147483648;
        for (const auto& element : buffer) {
            if (element.second == maximumValue) {

                result.push_back (element.first);
            }
            else if (element.second > maximumValue) {

                maximumValue = element.second;
                maximumKey = element.first;

                result.clear();
                result.push_back (element.first);
            }
        }

        return result;
    }
};