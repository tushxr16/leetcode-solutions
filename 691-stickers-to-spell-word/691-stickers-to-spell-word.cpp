class Solution {
public:
    int minStickers(vector<string>& stickers, string target){
        int n = target.size();
        vector<int> dp(1<<n,INT_MAX);
        dp[0] = 0;
        for(int i=0;i<1<<n;++i){
            if(dp[i]!=INT_MAX)
            for(string sticker: stickers){
                int k = i;
                for(char ch: sticker){
                    for(int j=0;j<n;++j){
                        if(ch==target[j] && (k&(1<<j))==0){
                            k ^= 1<<j;
                            break;
                        }
                    }
                }
                dp[k] = min(dp[k],dp[i]+1);
            }
        }
        if(dp.back()==INT_MAX)
            return -1;
        return dp.back();
    }
};