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
        if (root) {
            prevMax = std::max(prevMax, root->val);
            int ans = countGoodNodes(root->left, prevMax) +
                      countGoodNodes(root->right, prevMax);

            ans += root->val >= prevMax ? 1 : 0;

            return ans;
        }
        return 0;
    }

    int goodNodes(TreeNode* root) { return countGoodNodes(root, INT_MIN); }
};