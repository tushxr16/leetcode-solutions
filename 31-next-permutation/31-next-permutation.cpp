class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int lastInc = -1, n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                lastInc = i;
            }
        }
        if(lastInc==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int idx = lastInc;
        for(int i=lastInc;i<n;i++){
            if(nums[i]<nums[idx] && nums[i]>nums[lastInc-1]){
                idx = i;
            }
        }
        swap(nums[lastInc-1],nums[idx]);
        sort(nums.begin()+lastInc,nums.end());
        return;
    }
};