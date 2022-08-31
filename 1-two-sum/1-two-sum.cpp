class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> st;
        for(int i=0;i<n;i++){
            if(st.find(target-nums[i])==st.end()){
                st[nums[i]] = i;
            }else{
                return {st[target-nums[i]],i};
            }
        }
        return {-1,-1};
    }
};