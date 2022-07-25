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
    void trav(TreeNode* root, int mx, int &cnt){
        if(root==nullptr){
            return;
        }
        if(root->val>=mx){
            cnt++;
            mx = root->val;
        }
        trav(root->left,mx,cnt);
        trav(root->right,mx,cnt);
        return;
    }
    
    int goodNodes(TreeNode* root) {
        int count = 0;
        trav(root,INT_MIN,count);
        return count;
    }
};