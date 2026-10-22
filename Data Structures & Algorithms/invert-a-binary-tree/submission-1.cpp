// Iterative dfs with a stack, O(n) time, O(h) space
// Each recursive call becomes a push
// The stack lives on the heap, so a tree can't overflow the call stack
// GPU shaders can't recurse, so BVH traversal on the GPU uses this same pattern
// back() then pop_back(): read the top before removing it.
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
    TreeNode* invertTree(TreeNode* root) {

        if(root == nullptr) return root;
        
        std::vector<TreeNode*> vec;
        vec.push_back(root);

        while(!vec.empty()){
            TreeNode* node = vec.back();
            vec.pop_back();
            std::swap(node->left, node->right);
            if(node->left != nullptr) vec.push_back(node->left);
            if(node->right != nullptr) vec.push_back(node->right);
        }

        return root;
    }

};
