/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool lcaUtil(TreeNode* root, TreeNode* target, vector<TreeNode*> &v){
        if(root==nullptr)
            return false;
        v.push_back(root);
        if(root == target)
            return true;
        if(lcaUtil(root->left,target,v) || lcaUtil(root->right,target,v))
            return true;
        v.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> P;        
        vector<TreeNode*> Q;
        if(lcaUtil(root,p,P) && lcaUtil(root,q,Q)){
            int i=1;
            int mn = min(Q.size(),P.size());
            for(i=1;i<mn;i++){
                if(P[i]!=Q[i])
                    break;
            }
            return P[i-1];
        }
        return nullptr;
    }
};