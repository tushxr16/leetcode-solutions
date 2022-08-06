class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), curr = 0, ans = INT_MIN;
        for(int i=0;i<n;i++){
            curr = max(nums[i],curr+nums[i]);
            ans = max(ans,curr);
        }
        return ans;
    }
};