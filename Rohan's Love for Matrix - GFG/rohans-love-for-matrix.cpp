// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    int firstElement(int n) 
    {
        int dp[n+1]={0};
        dp[0]=dp[1]=dp[2]=1;
        for(int i=3;i<n+1;i++){
            dp[i]=(dp[i-1]%1000000007+dp[i-2]%1000000007)%1000000007;
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.firstElement(n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends