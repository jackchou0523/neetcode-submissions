// Dfs passing the range down, O(n) time, O(h) stack
// Checking every node's ancestors bound
// Bounds are long long; node values could be INTMAX INTMIN
// Not using INFINITY bc it's a float, converting to int becomes undefined behavior causing case 1 false
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
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MAX, LLONG_MIN);
    }

private:
    bool isValid(TreeNode* node, long long upper, long long lower){
        if(node == nullptr) return true;
        if(node->val < upper && node->val > lower) {
            return isValid(node->left, node->val, lower) && isValid(node->right, upper, node->val);
        }

        return false;
    }
};
