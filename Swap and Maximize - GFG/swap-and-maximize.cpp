// { Driver Code Starts
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
}// } Driver Code Ends

void conquer(int arr[], int lo, int mid, int hi){
    int temp[hi-lo+1];
    int idx1 = lo, idx2 = mid+1, k = 0;
    while(idx1<= mid && idx2 <= hi){
        if(arr[idx1]<arr[idx2]){
            temp[k++] = arr[idx1++];
        }else{
            temp[k++] = arr[idx2++];
        }
    }
    while(idx1<=mid)
        temp[k++] = arr[idx1++];
    while(idx2<=hi)
        temp[k++] = arr[idx2++];
    for(int i=0;i<k;i++){
        arr[lo+i] = temp[i];
    }
    return;
}
void divide(int arr[], int lo, int hi){
    if(lo<hi){
        int mid = (lo+hi)/2;
        divide(arr,lo,mid);
        divide(arr,mid+1,hi);
        conquer(arr,lo,mid,hi);
    }
    return;
}
long long int maxSum(int arr[], int n)
{
    divide(arr,0,n-1);
    long long int sum = 0;
    for(int i=0;i<n;i++){
        sum+= abs(arr[i]-arr[n-i-1]);
    }
    return sum;
}