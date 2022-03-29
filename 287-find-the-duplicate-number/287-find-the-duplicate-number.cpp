class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bitset<100001> b;
        for(int i=0;i<nums.size();i++){
            if(b[nums[i]]!=0)return nums[i];
            else b[nums[i]]=1;
        }
        return -1;
    }
};