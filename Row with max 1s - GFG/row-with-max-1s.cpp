// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int>> &arr, int n, int m) {
	    int ans = m-1, col = -1;
	    for(int i=0;i<n;i++){
	        int j = ans;
	        while((j>-1) && (arr[i][j]==1)){
	            j--;
	        }
	        if(j!=ans){
	            col = i;
	            ans = j;
	        }
	    }
	    return col;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends