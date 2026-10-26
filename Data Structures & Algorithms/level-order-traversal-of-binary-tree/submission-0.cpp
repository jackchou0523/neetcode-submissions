// Bfs with queue, O(n) time, O(w) space
// Save level size before the inner loop, make sure it isnt reused
// queue keeps left to right order within level
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // return if null
        std::vector<vector<int>> ans;
        if(root == nullptr) return ans;

        std::queue<TreeNode*> pending;
        pending.push(root);

        while(!pending.empty()){
            std::vector<int> level;
            int level_size = pending.size();
            for(int i = 0; i < level_size; i++){
                TreeNode* node = pending.front();
                pending.pop();
                level.push_back(node->val);
                if(node->left != nullptr) pending.push(node->left);
                if(node->right != nullptr) pending.push(node->right);
            }
            ans.push_back(level);
        }

        return ans;
    }
};
