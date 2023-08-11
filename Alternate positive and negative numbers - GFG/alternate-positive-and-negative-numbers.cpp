//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    vector<int> pos,neg;
	    for(int i=0;i<n;i++){
	        if(arr[i]<0){
	            neg.push_back(arr[i]);
	        }else{
	            pos.push_back(arr[i]);
	        }
	    }
	    int m = min(pos.size(),neg.size());
	    for(int i=0;i<2*m;i++){
	        if(i&1){
	            arr[i] = neg[i/2];
	        }else{
	            arr[i] = pos[i/2];
	        }
	    }
	    for(int i=2*m;i<n;i++){
	        if(neg.size()==m){
	            arr[i] = pos[i-m];
	        }else{
	            arr[i] = neg[i-m];
	        }
	    }
	    return;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends