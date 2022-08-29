class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans  = nums[0], n = nums.size(), maxx = nums[0], minn = nums[0];
        for(int i=1;i<n;i++){
            int temp = maxx;
            maxx = max(maxx*nums[i],max(nums[i],minn*nums[i]));            
            minn = min(minn*nums[i],min(nums[i],temp*nums[i]));
            ans = max(ans,maxx);
        }
        return ans;
    }
};