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
    void countZigzag(TreeNode *root, bool prevRight, int length, int &maxLen) {
    if (root == nullptr)
        return;

    maxLen = max(maxLen, length);

    if (prevRight) {
        countZigzag(root->left, false, length + 1, maxLen);
        countZigzag(root->right, true, 1, maxLen);
    } else {
        countZigzag(root->right, true, length + 1, maxLen);
        countZigzag(root->left, false, 1, maxLen);
    }
}

int longestZigZag(TreeNode *root) {
    if (root == nullptr)
        return 0;
    int maxLen = 0;
    countZigzag(root->left, false, 1, maxLen);
    countZigzag(root->right, true, 1, maxLen);

    return maxLen;
}

};