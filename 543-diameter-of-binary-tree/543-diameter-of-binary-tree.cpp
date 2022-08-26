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
    int getHeight(TreeNode* root, int &dia){
        if(root==nullptr){
            return 0;
        }
        int lH = getHeight(root->left,dia);
        int rH = getHeight(root->right,dia);
        dia = max(dia,lH+rH);
        return 1 + max(lH,rH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        getHeight(root,dia);
        return dia;
    }
};