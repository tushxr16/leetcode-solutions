//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int lo = 1, hi = x, mid, ans = 1;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(mid*mid==x){
                return mid;
            }else if(mid*mid>x){
                hi = mid-1;
            }else{
                ans = mid;
                lo = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends