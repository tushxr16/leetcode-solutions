class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        int n = nums1.size(), m = nums2.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
            mp[nums1[i]] = 0;
        for(int i=0;i<m;i++)
            if(mp.find(nums2[i])!=mp.end())
                mp[nums2[i]] = 1;
        for(auto x:mp)
            if(x.second==1)
                ans.push_back(x.first);
        return ans;
    }
};