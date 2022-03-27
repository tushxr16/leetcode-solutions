class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> sums(mat.size(),{0,0});
        for(int i=0;i<mat.size();i++){
            int sum = accumulate(mat[i].begin(),mat[i].end(),0);
            sums[i]={sum,i};
        }
        sort(sums.begin(),sums.end());
        vector<int> ans;
        for(int i=0;i<k;i++)ans.push_back(sums[i].second);
        return ans;
    }
};