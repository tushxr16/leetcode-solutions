//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mcm(int i, int n, int arr[], vector<vector<int>> &dp, int &N){
        if(i==n){
            return 0;
        }
        if(dp[i][n]!=-1)
            return dp[i][n];
            
        int ans = INT_MAX;
        for(int j=i;j<n;j++){
            ans = min(ans, arr[i-1]*arr[j]*arr[n] + mcm(i,j,arr,dp,N) + mcm(j+1,n,arr,dp,N));
        }
        return dp[i][n] = ans;
    }
    
    int matrixMultiplication(int N, int arr[]){
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return mcm(1,N-1,arr,dp,N);
    }
};

//{ Driver Code Starts.

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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends