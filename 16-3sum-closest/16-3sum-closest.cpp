class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int maxDiff = INT_MAX, ans = INT_MAX, n = nums.size();
        for(int i=0;i<n-2;i++){
            int lo = i+1, hi = n-1;
            while(lo<hi){
                int sum = nums[i] + nums[lo] + nums[hi];
                if(abs(sum-target)<=maxDiff){
                    maxDiff = abs(sum-target);
                    ans = sum;
                }
                if(sum>target){
                    hi--;
                }else if(sum<target){
                    lo++;
                }else{
                    return target;
                }
            }
        }
        return ans;
    }
};