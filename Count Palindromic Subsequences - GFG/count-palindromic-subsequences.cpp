// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int mod = 1e9 + 7;
    long long int CPS(vector<vector<long long int>> &dp, string &str, int i, int j){
        if(i==j)
            return dp[i][j] = 1;
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(str[i]==str[j])
            return dp[i][j] = (CPS(dp,str,i+1,j)%mod + CPS(dp,str,i,j-1)%mod + 1 + mod)%mod;
        return dp[i][j] = (mod + CPS(dp,str,i+1,j)%mod + CPS(dp,str,i,j-1)%mod - CPS(dp,str,i+1,j-1)%mod)%mod;
    }
    long long int  countPS(string str)
    {
        vector<vector<long long int>> dp(1001,vector<long long int>(1001,-1));
        long long int ans = CPS(dp,str,0,str.size()-1);
        return ans;
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends