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
            result.push_back(nodeQueue.back()->val);

            auto temp = nodeQueue;
            nodeQueue = std::queue<TreeNode*>();

            while (!temp.empty()) {
                if (temp.front()->left != nullptr) {
                    nodeQueue.push(temp.front()->left);
                }
                if (temp.front()->right != nullptr) {
                    nodeQueue.push(temp.front()->right);
                }
                temp.pop();
            }
        }

        return result;
    }
};