//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	long long int mod = 1e9 + 7;
	vector<vector<int>> dp;
	int ways(string s, string t, int i, int j){
	    if(j==t.size()) return 1;
	    if(i>s.size()) return 0;
	    
	    if(dp[i][j]!=-1) return dp[i][j];
	    
	    if(s[i]==t[j])  
	        return dp[i][j] = (ways(s,t,i+1,j) + ways(s,t,i+1,j+1))%mod;
	    else
	        return dp[i][j] = ways(s,t,i+1,j)%mod;
	}
	int TotalWays(string str){
	    string geeks = "GEEKS";
	    int n = str.size(), m = geeks.size();
	    dp.resize(n+1,vector<int>(m+1,-1));
	    return ways(str,geeks,0,0)%mod;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalWays(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends