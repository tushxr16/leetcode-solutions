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
    bool trav(TreeNode* root, int &k, unordered_set<int> &st){
        if(root==nullptr){
            return false;
        }
        if(st.find(k-root->val)!=st.end()){
            return true;
        }else{
            st.insert(root->val);
            return trav(root->left,k,st) || trav(root->right,k,st);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return trav(root,k,st);
    }
};