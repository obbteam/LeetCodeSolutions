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
    int countDepth(TreeNode* root, int count) {
        if (root == nullptr) return count;
        int left = countDepth(root->left, count + 1);
        int right = countDepth(root->right, count + 1);
        return std::max(left, right);
    }
    int maxDepth(TreeNode* root) {
        return countDepth(root, 0);
    }
};