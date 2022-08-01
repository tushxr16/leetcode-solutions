class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        unordered_set<int> st;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                long long lo = j+1, hi = n-1, tempSum = nums[i] + nums[j];
                while(lo<hi){
                    long long sum = tempSum + nums[lo] + nums[hi];
                    if(sum<target){
                        lo++;
                    }else if(sum>target){
                        hi--;
                    }else{
                        ans.insert({nums[i],nums[j],nums[lo],nums[hi]});
                        lo++;
                    }
                }
            }
        }
        vector<vector<int>> ans2(ans.begin(),ans.end());
        return ans2;
    }
};