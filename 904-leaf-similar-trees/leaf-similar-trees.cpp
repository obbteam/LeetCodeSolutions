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
    void treeLeaves(TreeNode* root, std::vector<int>& leaves) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            leaves.emplace_back(root->val);
            return;
        }

        treeLeaves(root->left, leaves);
        treeLeaves(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> leaves1, leaves2;
        treeLeaves(root1, leaves1);
        treeLeaves(root2, leaves2);
        if (leaves1.size() != leaves2.size())
            return false;
        for (int i = 0; i < leaves1.size(); ++i) {
            if (leaves1[i] != leaves2[i])
                return false;
        }
        return true;
    }
};