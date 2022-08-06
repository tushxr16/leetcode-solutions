class Solution {
public:
    void solve(int k, int curr, int target,vector<int> &candidates, vector<vector<int>> &ans, vector<int> temp){
        if(curr>target){
            return;
        }
        if(curr==target){
            ans.push_back(temp);
        }
        
        int n = candidates.size();
        
        for(int i=k;i<n;i++){
            curr+=candidates[i];
            temp.push_back(candidates[i]);
            solve(i,curr,target,candidates,ans,temp);
            curr-=candidates[i];
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,0,target,candidates,ans,temp);
        return ans;
    }
};