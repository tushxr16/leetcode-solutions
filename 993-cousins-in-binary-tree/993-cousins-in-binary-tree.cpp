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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        if(root){
            q.push(root);
        }
        while(!q.empty()){
            int n = q.size();
            int foundx = -1, foundy = -1;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->val==x)
                    foundx = i+1;
                if(node->val==y)
                    foundy = i+1;
                if(node->left && node->right){
                    if(node->left->val == x && node->right->val == y)return false;
                    if(node->left->val == y && node->right->val == x)return false;
                }
                if(node->left)
                    q.push(node->left);                
                if(node->right)
                    q.push(node->right);
            }
            if(foundx!=-1 && foundy!=-1){
                return true;
            }
        }
        return false;
    }
};