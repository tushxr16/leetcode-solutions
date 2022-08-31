class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        int i = 0, j = nums.size()-1;
        while(i<=j){
            if(abs(nums[i])>abs(nums[j])){
                res.push_back(nums[i]*nums[i]);
                i++;
            }else{
                res.push_back(nums[j]*nums[j]);
                j--;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};