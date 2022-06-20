// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int lo = 0, hi = n-1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(arr[mid]==x){
            int first = mid, last = mid;
            while(first>=0 && arr[first]==x)first--;
            while(last<n && arr[last]==x)last++;
            return {first+1,last-1};
        }else if(arr[mid]<x){
            lo = mid+1;
        }else hi = mid-1;
    }
    return {-1,-1};
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends