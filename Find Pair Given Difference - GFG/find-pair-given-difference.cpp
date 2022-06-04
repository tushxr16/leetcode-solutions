// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    sort(arr,arr+size);
    for(int i=0;i<size;i++){
        int curr = arr[i];
        int lo = 0, hi = size, mid;
        while(lo<=hi){
            mid = (hi+lo)/2;
            if(curr-n==arr[mid] && mid!=i)return true;
            else if(curr-n>arr[mid])lo = mid+1;
            else hi = mid-1;
        }
    }
    return false;
}