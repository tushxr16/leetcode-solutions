class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, majorityElement = nums[0], n = nums.size();
        for(int i=1;i<n;i++){
            if(majorityElement == nums[i]){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt==0){
                cnt++;
                majorityElement = nums[i];
            }
        }
        return majorityElement;
    }
};