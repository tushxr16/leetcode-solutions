class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        map<int,int> cond1, cond2;
        vector<int> tmp,tmp2;
        int n = matches.size();
        for(int i=0;i<n;i++){
            cond1[matches[i][0]]++;
            cond2[matches[i][1]]++;
        }
        for(auto x:cond2){
            if(cond1.find(x.first)!=cond1.end())
                cond1.erase(x.first);
        }
        for(auto x:cond1){
            tmp.push_back(x.first);
        }
        ans.push_back(tmp);
        for(auto x:cond2){
            if(x.second==1)
                tmp2.push_back(x.first);
        }
        ans.push_back(tmp2);
        return ans;
    }
};