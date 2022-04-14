class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,int>> v(75,{0,0});
        for(int i=0;i<s.size();i++){v[s[i]-'0'].first++;v[s[i]-'0'].second=s[i]-'0';}
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        s.clear();
        for(int i=0;i<75;i++){
            while(v[i].first--)s.push_back('0'+v[i].second);
        }
        return s;
    }
};