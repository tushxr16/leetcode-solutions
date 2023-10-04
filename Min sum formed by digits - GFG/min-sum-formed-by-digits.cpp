//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        long long int x = 0 , y = 0;
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        while(!pq.empty()){
            x = x*10 + pq.top();
            pq.pop();
            if(!pq.empty()){
                y = y*10 + pq.top();
                pq.pop();
            }
        }
        
        return x+y;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends