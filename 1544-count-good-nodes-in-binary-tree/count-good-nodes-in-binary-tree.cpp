/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int countGoodNodes(TreeNode* root, int prevMax) {
        if (root == nullptr) {
            return 0;
        }

        int ans = root->val < prevMax ? 0 : 1;

        prevMax = std::max(prevMax, root->val);

        int left = countGoodNodes(root->left, prevMax);
        int right = countGoodNodes(root->right, prevMax);

        return left + right + ans;
    }

    int goodNodes(TreeNode* root) { return countGoodNodes(root, INT_MIN); }
};