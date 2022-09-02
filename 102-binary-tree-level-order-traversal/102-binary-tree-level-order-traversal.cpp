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
        vector<vector<int>> level_order;
        queue<TreeNode*> bfs_queue;
        if(root)
            bfs_queue.push(root);
        
        while(!bfs_queue.empty()){
            int size_of_level = bfs_queue.size();
            vector<int> current_level;
            for(int i=0;i<size_of_level;i++){
                TreeNode* node = bfs_queue.front();
                bfs_queue.pop();
                current_level.push_back(node->val);
                if(node->left){
                    bfs_queue.push(node->left);
                }
                if(node->right){
                    bfs_queue.push(node->right);
                }
            }
            level_order.push_back(current_level);
        }
        return level_order;
    }
};