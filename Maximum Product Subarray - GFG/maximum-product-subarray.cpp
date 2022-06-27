// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int N) {
	    long long p = 1, n = 1, ans = INT_MIN;
	    for(int i=0;i<N;i++){
	        p*=arr[i];
	        n*=arr[N-1-i];
	        ans = max(ans,max(n,p));
	        if(p==0)
	            p=1;
	        if(n==0)
	            n=1;
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends