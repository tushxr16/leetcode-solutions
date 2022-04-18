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
    void recur(TreeNode* root, int k, vector<int> &arr){
        if(root==nullptr)return;
        recur(root->left,k,arr);
        arr.push_back(root->val);        
        recur(root->right,k,arr);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        recur(root,k,ans);
        return ans[k-1];
    }
};