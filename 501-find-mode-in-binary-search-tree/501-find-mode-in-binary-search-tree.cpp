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
    unordered_map<int,int> mp;
    void trav(TreeNode* root){
        if(!root)
            return;
        mp[root->val]++;
        trav(root->left);
        trav(root->right);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        vector<pair<int,int>> temp;
        trav(root);
        for(auto x: mp){
            temp.push_back({x.second,x.first});
        }
        sort(temp.begin(),temp.end(),greater<pair<int,int>>());
        if(temp.size()>0)
            ans.push_back(temp[0].second);
        for(int i=1;i<temp.size();i++){
            if(temp[i].first!=temp[i-1].first){
                break;
            }else{
                ans.push_back(temp[i].second);
            }
        }
        return ans;
    }
};