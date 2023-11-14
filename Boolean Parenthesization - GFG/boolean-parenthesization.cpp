//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1003;
    
    int mcm(int i, int j, string &s, bool isTrue, vector<vector<vector<int>>> &dp){
        if(i>j)
            return 0;
        if(i==j){
            if(isTrue)
                return s[i]=='T';
            else
                return s[i]=='F';
        }
        if(dp[i][j][isTrue]!=-1)
            return dp[i][j][isTrue]%mod;
        int count = 0;
        for(int k=i+1;k<=j-1;k+=2){
            
            int leftTrue = mcm(i,k-1,s,1,dp);
            int rightTrue = mcm(k+1,j,s,1,dp);
            int leftFalse = mcm(i,k-1,s,0,dp);
            int rightFalse = mcm(k+1,j,s,0,dp);
            int res = 0;
            
            if(s[k]=='&'){
                if(isTrue)
                    res = (leftTrue * rightTrue)%mod;
                else
                    res = (leftTrue*rightFalse + leftFalse*rightTrue + leftFalse*rightFalse)%mod;
            }else if(s[k]=='|'){
                if(isTrue)
                    res = (leftTrue*rightFalse + leftFalse*rightTrue + leftTrue*rightTrue)%mod;
                else
                    res = (rightFalse*leftFalse)%mod;
            }else if(s[k]=='^'){
                if(isTrue)
                    res = (leftTrue*rightFalse + leftFalse*rightTrue)%mod;
                else
                    res = (leftTrue*rightTrue + leftFalse*rightFalse)%mod;
            }
            if(res)
                count = (count + res)%mod;
        }
        return  dp[i][j][isTrue] = count%mod;
    }
    int countWays(int N, string S){
        vector<vector<vector<int>>> dp(N, vector<vector<int>> (N, vector<int>(2,-1)));
        return mcm(0,N-1,S,1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends