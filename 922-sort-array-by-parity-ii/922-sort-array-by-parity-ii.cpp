class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ans(n);
        int o = 1, e = 0;
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                ans[o] = nums[i];
                o+=2;
            }else{
                ans[e] = nums[i];
                e+=2;
            }
        }
        return ans;
    }
};