class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size(), ans = 0;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(st.find(nums[i]-1)==st.end()){
                int cnt = 1, curr = nums[i];
                while(st.find(curr+1)!=st.end()){
                    cnt++;
                    curr++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};