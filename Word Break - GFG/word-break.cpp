//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        
        int n = A.size(), m = B.size();
        vector<bool> dp(n+1,false);
        dp[n] = true;
        
        for(int i=n;i>=0;i--){
            for(int j=0;j<m;j++){
                int wordSize = B[j].size();
                if(i+wordSize<=n && A.substr(i,wordSize)==B[j]){
                    dp[i] = dp[i+wordSize];
                }
                if(dp[i]) break;
            }
        }
        
        return dp[0];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends