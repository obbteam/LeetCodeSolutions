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
    std::vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};

        std::vector<int> result;
        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            TreeNode* rightSide = nullptr;

            auto size = nodeQueue.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                if (node) {
                    rightSide = node;
                    if (node->left)
                        nodeQueue.push(node->left);
                    if (node->right)
                        nodeQueue.push(node->right);
                }
            }

            if (rightSide) {
                result.push_back(rightSide->val);
            }
        }

        return result;
    }
};