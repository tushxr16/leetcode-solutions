class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum&1){
            return false;
        }
        vector<vector<bool>> dp(n+1,vector<bool>((sum/2)+1,false));
        dp[0][0] = true;
        if(nums[0]<=sum/2)
            dp[0][nums[0]] = true;
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum/2;j++){
                if(j<nums[i]){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[n-1][sum/2];
    }
};