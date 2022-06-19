class Solution {
    private:
        map<int,vector<int>> mp;
    public:
        Solution(vector<int>& nums) {
            int n = nums.size();
            for(int i=0;i<n;i++){
                mp[nums[i]].push_back(i);
            }
        }
    
        int pick(int target) {
            int n = rand()%mp[target].size();
            return mp[target][n];
        }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */