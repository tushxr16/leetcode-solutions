class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)return {};
        vector<vector<int>> ret;
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int left=i+1,high=nums.size()-1;
            while(left<high){
                int sum=nums[i]+nums[left]+nums[high];
                if(sum==0){vector<int> tmp={nums[i],nums[left],nums[high]};
                           ans.insert(tmp);
                           left++;high--;
                          }
                else if(sum>0)high--;
                else left++;
            }
        }
        copy(ans.begin(),ans.end(),back_inserter(ret));
        return ret;
    }
};