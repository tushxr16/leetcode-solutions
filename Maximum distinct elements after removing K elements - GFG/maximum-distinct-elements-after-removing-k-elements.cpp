//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxDistinctNum(int arr[], int n, int k){
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[arr[i]]++;
        int duplicates = n-mp.size();
        if(duplicates>=k){
            return mp.size();
        }else{
            return mp.size()-(k-duplicates);
        }
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i,k;
	cin>>n>>k;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout <<ob.maxDistinctNum(arr, n, k)<<"\n";
	  }
	return 0;
}

// } Driver Code Ends