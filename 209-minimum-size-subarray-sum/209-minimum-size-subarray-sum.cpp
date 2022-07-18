class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), sum = 0, ans = INT_MAX, lo = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            while(sum>=target){
                ans = min(ans,i-lo+1);
                sum -= nums[lo++];
            }
        }
        if(ans==INT_MAX)
                return 0;
        else
            return ans;
    }
};