class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans = {1,1};
        int n = nums.size();
        int p = n;
        for(int i=0;i<n;i++){
            nums[i]--;
            int idx = nums[i]%p;
            nums[idx] += p;
        }
        for(int i=0;i<n;i++){
            if(nums[i]/p==0)
                ans[1] = i+1;
            if(nums[i]/p==2)
                ans[0] = i+1;
        }
        return ans;
    }
};