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
    
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        if(root)
            q.push({root,0});
        else{
            return 0;
        }
        unsigned int ans = 0;
        while(!q.empty()){
            int n = q.size();
            unsigned int mn = INT_MAX, mx = INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front().first;
                unsigned int h = q.front().second;
                mn = min((int)mn,(int)h);
                mx = max((int)mx,(int)h);
                q.pop();
                if(node->left){
                    q.push({node->left,2*h+1});
                }
                if(node->right){
                    q.push({node->right,2*h+2});
                }
            }
            ans = max(ans,mx-mn+1);
        }
        return ans;
    }
};