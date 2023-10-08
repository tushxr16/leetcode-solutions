//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int f(int i, int n, int k, vector<int> &arr, vector<int> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];
        int ans = INT_MIN, mx = INT_MIN;
        for(int j=i;j<min(i+k,n);j++){
            mx = max(mx, arr[j]);
            ans = max(ans, mx*(j-i+1) + f(j+1,n,k,arr,dp));
        }
        return dp[i] = ans;
    }
    int solve(int n, int k, vector<int>& arr){
        vector<int> dp(n,-1);
        return f(0,n,k,arr,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends