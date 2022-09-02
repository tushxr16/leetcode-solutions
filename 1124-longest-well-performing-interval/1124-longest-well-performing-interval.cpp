class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans = 0, n = hours.size();
        hours[0] = hours[0]>8?1:-1;
        for(int i=1;i<n;i++){
            hours[i] = (hours[i]>8?hours[i-1]+1:hours[i-1]-1);
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(hours[i]>0){
                ans = max(ans,i+1);
            }
            else if(mp.find(hours[i]-1)!=mp.end()){
                ans = max(ans,i-mp[hours[i]-1]);
            }else if(mp.find(hours[i])==mp.end()){
                mp[hours[i]] = i;
            }
        }
        return ans;
    }
};