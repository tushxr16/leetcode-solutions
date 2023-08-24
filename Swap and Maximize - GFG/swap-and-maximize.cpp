//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    int sum = arr[n/2]-arr[0];
    bool flag = true;
    for(int i=0, j=n-1;i<(n+1)/2;){
        sum += (arr[j]-arr[i]);
        if(flag){
            i++;
        }else{
            j--;
        }
        flag = !flag;
    }
    return sum;
}