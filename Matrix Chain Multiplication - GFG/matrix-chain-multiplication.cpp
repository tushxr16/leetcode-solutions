// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mcm(int i, int j, int arr[], vector<vector<int>> &dp){
        if(j==i){
            return 0;
        }
        
        int mini = 1e9;
        
        if(dp[i][j]!=mini){
            return dp[i][j];
        }
        
        for(int k=i;k<j;k++){
            int steps = arr[i-1]*arr[k]*arr[j] + mcm(i,k,arr,dp) + mcm(k+1,j,arr,dp);
            if(steps<mini)
                mini = steps;
        }
        
        return dp[i][j] = mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N+1, vector<int>(N+1,1e9));
        return mcm(1,N-1,arr,dp);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends