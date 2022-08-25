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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        if(root){
            q.push({root,{0,0}});
        }
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                pair<TreeNode*,pair<int,int>> p = q.front();
                q.pop();
                
                TreeNode* node = p.first;
                int h = p.second.first, l = p.second.second;
                
                mp[h][l].insert(node->val);
                
                if(node->left)
                    q.push({node->left,{h-1,l+1}});
                if(node->right)
                    q.push({node->right,{h+1,l+1}});
            }
        }
        for(auto x: mp){
            vector<int> tmp;
            for(auto k: x.second){
                for(auto l: k.second){
                    tmp.push_back(l);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};