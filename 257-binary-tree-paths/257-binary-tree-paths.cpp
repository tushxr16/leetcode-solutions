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
    void trav(TreeNode* root, vector<string> &ans, string s){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr && root->right==nullptr){
            s+=(to_string(root->val));
            ans.push_back(s);
            return;
        }
        s+=(to_string(root->val));
        s.push_back('-');
        s.push_back('>');
        trav(root->left,ans,s);
        trav(root->right,ans,s);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        trav(root,ans,"");
        return ans;
    }
};