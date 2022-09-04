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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag_traversal;
        queue<TreeNode*> bfs;
        if(root){
            bfs.push(root);
        }
        bool rev = false;
        while(!bfs.empty()){
            int n = bfs.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode* top = bfs.front();
                bfs.pop();
                level.push_back(top->val);
                if(top->left){
                    bfs.push(top->left);
                }
                if(top->right){
                    bfs.push(top->right);
                }
            }
            if(rev){
                reverse(level.begin(),level.end());
            }
            rev = !rev;
            zigzag_traversal.push_back(level);
        }
        return zigzag_traversal;
    }
};