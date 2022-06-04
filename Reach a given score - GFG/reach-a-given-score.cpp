// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
long long int count(long long int n)
{
	long long int table[n+1];
	memset(table, 0, sizeof(table));
	table[0] = 1;
	for(long long int i=3;i<=n;i++){
	    if(i-3>=0)table[i]+=table[i-3];
	}
	for(long long int i=5;i<=n;i++){
	    table[i]+=table[i-5];
	}
	for(long long int i=10;i<=n;i++){
	    table[i]+=table[i-10];
	}
	return table[n];
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends