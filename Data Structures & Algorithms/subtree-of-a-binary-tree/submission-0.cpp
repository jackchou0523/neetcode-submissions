// check each node in root
// O(m * n) time; up to m nodes, each compares n nodes, O(h) stack space
// || short circuits
// isSameTree reused as private helper
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;
        if(isSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }

private:
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr && subRoot == nullptr) return true;
        if(root == nullptr || subRoot == nullptr) return false;
        if(root->val != subRoot->val) return false;

        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }
};
