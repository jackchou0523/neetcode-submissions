// Bfs with queue, O(n) time, O(w) space, w = widest level
// save the queue size before each level to lock the size
// each completed level + 1 to depth
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        std::queue<TreeNode*> pending;
        pending.push(root);
        int depth = 0;

        while(!pending.empty()){
            // run queue size times, nodes of this level saved
            int level_size = pending.size();
            for(int i = 0; i < level_size; i++){
                TreeNode* node = pending.front();
                pending.pop();
                if(node->left != nullptr){
                    pending.push(node->left);
                }
                if(node->right != nullptr){
                    pending.push(node->right);
                }
            }
            depth += 1;

        }

        return depth;
    }
};
