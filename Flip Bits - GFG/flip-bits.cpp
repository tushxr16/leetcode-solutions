//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int curr = 0, ans = 0, ones = 0;
        for(int i=0;i<n;i++){
            if(a[i]==1)
                ones++;
            curr = max((a[i]==0?1:-1),curr+(a[i]==0?1:-1));
            ans = max(ans,curr);
        }
        return ans+ones;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends