class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0,left=0,right=height.size()-1;
        while(left<right){
            ans = max(ans,(right-left)*(height[left]<height[right]?height[left]:height[right]));
            height[left]>height[right]?right--:left++;
        }
        return ans;
    }
};