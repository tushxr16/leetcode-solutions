class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> num = nums;
        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        while(prev_permutation(num.begin(),num.end())){
            ans.push_back(num);
        }
        return ans;
    }
};