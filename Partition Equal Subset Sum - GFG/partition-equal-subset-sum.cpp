// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum&1)   
            return false;
        
        vector<vector<bool>> dp(n+1,vector<bool>(sum/2,false));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum/2;j++){
                if(i==0 || j==0){
                    dp[i][j] = false;
                }else if(arr[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }else if(arr[i-1]==j){
                    dp[i][j] = true;
                }else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
        return dp[n][sum/2];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends