//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    vector<int> dp;
    int loot(int arr[], int n, int i){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i] = max(arr[i]+loot(arr,n,i+2),loot(arr,n,i+1));
    }
    int FindMaxSum(int arr[], int n)
    {
        dp.resize(n,-1);
        dp[0] = arr[0];
        dp[1] = max(arr[1],arr[0]);
        
        for(int i=2;i<n;i++){
            dp[i] = max(arr[i]+dp[i-2],dp[i-1]);
        }
        
        return dp[n-1];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends