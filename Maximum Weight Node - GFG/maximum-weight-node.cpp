//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      vector<int> dp(N,0);
      for(int i=0;i<N;i++){
          if(Edge[i]!=-1){
              dp[Edge[i]] += i;
          }
      }
      int idx = 0, mx = dp[0];
      for(int i=0;i<N;i++){
          if(mx==dp[i]){
              idx = max(idx,i);
          }
          if(mx<dp[i]){
              mx = dp[i];
              idx = i;
          }
      }
      return idx;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends