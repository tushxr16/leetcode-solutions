class Solution {
    private:
        vector<int> v;
    public:
        Solution(vector<int>& nums) {
            v = nums;
        }
    
        int pick(int target) {
            vector<int> idx;
            for(int i=0;i<v.size();i++)
                if(v[i]==target)
                    idx.push_back(i);
            return idx[rand()%idx.size()];
        }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */