class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int hi1=0,hi2=0;
        for(int i=0;i<nums.size();i++){
            if(hi1<=nums[i]){
                hi2=hi1;
                hi1=nums[i];
            }else if(hi2<=nums[i])hi2=nums[i];
        }
        return (hi1-1)*(hi2-1);
    }
};