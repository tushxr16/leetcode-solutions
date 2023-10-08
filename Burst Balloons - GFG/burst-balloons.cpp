//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int mcm(int i, int k, vector<int> &arr, vector<vector<int>> &dp){
        if(i>k){
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int ans = INT_MIN;
        for(int j=i;j<=k;j++){
            ans = max(ans, arr[i-1]*arr[j]*arr[k+1] + mcm(i,j-1,arr,dp) + mcm(j+1,k,arr,dp));
        }
        return dp[i][k] = ans;
    }
    int maxCoins(int N, vector<int> &arr) {
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        return mcm(1,N,arr,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends