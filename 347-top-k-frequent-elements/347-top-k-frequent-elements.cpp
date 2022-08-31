class Solution {
public:
        
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<pair<int,int>> v;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto x: mp){
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>> ());
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};