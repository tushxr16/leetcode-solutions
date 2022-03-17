class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid=0;
        while(mid<=high){
            if(nums[mid]==0)swap(nums[low++],nums[mid++]);
            else if(nums[mid]==1)mid++;
            else swap(nums[mid],nums[high--]);
        }
        // int a0=0,a1=0,a2=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0)a0++;
        //     if(nums[i]==1)a1++;                                                                             if(nums[i]==2)a2++;
        // }
        // for(int i=0;i<a0;i++)nums[i]=0;
        // for(int i=a0;i<a1+a0;i++)nums[i]=1;
        // for(int i=a0+a1;i<nums.size();i++)nums[i]=2;
    }
};