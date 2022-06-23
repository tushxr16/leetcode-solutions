// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        sort(A,A+n);
        sort(B,B+m);
        
        long long sum1 = 0, sum2 = 0;
        for(int i=0;i<n;i++)
            sum1+=(A[i]);
        for(int i=0;i<m;i++)
            sum2+=(B[i]);
        if((sum1-sum2)%2!=0)
            return -1;
        for(int i=0;i<n;i++){
            int lo = 0, hi = m-1;
            long long target = A[i] + (sum2-sum1)/2;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(B[mid]==target)
                    return 1;
                else if(B[mid]>target)
                    hi = mid-1;
                else 
                    lo = mid+1;
            }
        }
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
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends