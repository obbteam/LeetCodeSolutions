/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    std::pair<TreeNode*, int> helper(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (!root) return {nullptr, 0};

    auto [leftLca,  leftCnt ] = helper(root->left,  p, q);
    if (leftLca) return {leftLca, 2};               // LCA already found below

    auto [rightLca, rightCnt] = helper(root->right, p, q);
    if (rightLca) return {rightLca, 2};             // LCA already found below

    int cnt = leftCnt + rightCnt +
              (root == p) + (root == q);            // how many targets in this subtree

    if (cnt == 2) return {root, 2};                 // this node is the first that sees both

    return {nullptr, cnt};                          // otherwise just bubble the count up
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    return helper(root, p, q).first;
}
};