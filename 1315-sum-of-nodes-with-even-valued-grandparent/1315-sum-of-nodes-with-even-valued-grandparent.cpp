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
    int addTheValuesOfGrandParent(TreeNode* root){
        int sum = 0;
        if(root->left){
            if(root->left->left)
                sum += root->left->left->val;
            if(root->left->right)
                sum += root->left->right->val;
        }
        if(root->right){
            if(root->right->left)
                sum += root->right->left->val;
            if(root->right->right)
                sum += root->right->right->val;
        }
        return sum;
    }
    void trav(TreeNode* root, int &sum){
        if(!root){
            return;
        }
        if(((root->val)%2)==0)
            sum += addTheValuesOfGrandParent(root);
        trav(root->left,sum);
        trav(root->right,sum);
        return;
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        trav(root,sum);
        return sum;
    }
};