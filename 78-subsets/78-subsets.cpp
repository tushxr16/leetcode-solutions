class Solution {
public:
    set<vector<int>> ans;
    void Util(vector<int> nums, vector<int> v, int start){
        for(int i=start;i<nums.size();i++){
            Util(nums,v,i+1);
            v.push_back(nums[i]);
            Util(nums,v,i+1);
            ans.insert(v);
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        Util(nums,{},0);
        vector<vector<int>> ANS(ans.begin(),ans.end());
        ANS.push_back({});
        return ANS;
    }
};