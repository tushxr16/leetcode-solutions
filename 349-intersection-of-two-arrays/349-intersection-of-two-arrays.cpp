class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        int n = nums1.size(), m = nums2.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
            mp[nums1[i]] = 0;
        for(int i=0;i<m;i++)
            if(mp.find(nums2[i])!=mp.end()){
                ans.push_back(nums2[i]);
                mp.erase(nums2[i]);
            }                
        return ans;
    }
};