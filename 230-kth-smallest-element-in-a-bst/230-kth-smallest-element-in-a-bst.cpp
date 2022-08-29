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
    
    int kthSmallest(TreeNode* root, int &k) {
        if(root==nullptr){
            return -1;
        }
        int val = kthSmallest(root->left,k);
        k--;
        if(k==0){
            return root->val;
        }else if(k<0){
            return val;
        }
        return kthSmallest(root->right,k);
    }
};