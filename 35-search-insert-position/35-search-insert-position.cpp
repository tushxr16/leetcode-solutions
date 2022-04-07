class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size(),mid;
        while(low<high){
            mid=(low+high)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)high--;
            else low++;
        }
        return low;
    }
};