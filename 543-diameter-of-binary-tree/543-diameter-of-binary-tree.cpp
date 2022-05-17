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
    int highT(TreeNode* t){
        if(t==nullptr)return 0;
        return 1+max(highT(t->left),highT(t->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;
        int lhighT = highT(root->left);
        int rhighT = highT(root->right);
        
        int lDia = diameterOfBinaryTree(root->left);
        int rDia = diameterOfBinaryTree(root->right);
        
        return max(lhighT+rhighT,max(lDia,rDia));
    }
};