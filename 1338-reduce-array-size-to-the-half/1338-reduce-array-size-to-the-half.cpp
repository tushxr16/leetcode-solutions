class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])!=mp.end())mp[arr[i]]++;
            else mp[arr[i]]=1;
        }
        priority_queue<pair<int,int>> p;
        for(auto x:mp){
            p.push({x.second,x.first});
        }
        int sum=0,cnt=0;
        while(arr.size()-sum>arr.size()/2){
            sum+=p.top().first;
            cnt++;
            p.pop();
        }
        return cnt;
    }
};