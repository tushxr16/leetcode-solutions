class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        map<int,int> mp;
        int n = matches.size();
        for(int i=0;i<n;i++){
            mp[matches[i][0]]++;
        }
        for(int i=0;i<n;i++){
            if(mp.find(matches[i][1])!=mp.end())
                mp.erase(matches[i][1]);
        }
        vector<int> winners;
        for(map<int,int>::iterator it = mp.begin(); it!=mp.end();it++){
            winners.push_back((*it).first);
        }
        ans.push_back(winners);
        mp.clear();
        for(int i=0;i<n;i++){
            mp[matches[i][1]]++;
        }
        winners.clear();
        for(auto x:mp){
            if(x.second==1)
                winners.push_back(x.first);
        }
        ans.push_back(winners);
        return ans;
    }
};