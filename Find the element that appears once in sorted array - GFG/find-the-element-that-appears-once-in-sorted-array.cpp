// { Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        if(arr[0]!=arr[1])return arr[0];
        for(int i=0;i<n-2;i++){
            if(arr[i]!=arr[i+1] && arr[i+1]!=arr[i+2])return arr[i+1];
        }
        if(arr[n-1]!=arr[n-2])return arr[n-1];
        return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}  // } Driver Code Ends