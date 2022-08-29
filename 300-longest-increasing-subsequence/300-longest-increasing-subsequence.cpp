class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> lis(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    lis[i] = max(lis[i],lis[j]+1);
                }
            }
            ans = max(ans,lis[i]);
        }
        return ans;
    }
};