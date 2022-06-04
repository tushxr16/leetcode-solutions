// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findWinner(int N, int X, int Y)
	{
		int dp[N+1];
		dp[0] = 0, dp[1] = 1;
		for(int i=2;i<=N;i++){
		    dp[i] = 0;
		    if(i-1>=0 && !dp[i-1])dp[i] = 1;
		    if(i-X>=0 && !dp[i-X])dp[i] = 1;
		    if(i-Y>=0 && !dp[i-Y])dp[i] = 1;
		}
		return dp[N];
	}

};
	

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends