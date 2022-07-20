class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string r;
        int n = s.size();
        for(int i=0;i<n;i++){
            r.push_back(s[n-1-i]);
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==r[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};