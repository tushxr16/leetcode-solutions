// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

int LargButMinFreq(int arr[], int n) {
    map<int,int> mp;
    map<int,vector<int>> pm;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto x: mp){
        pm[x.second].push_back(x.first);
    }
    for(auto x:pm){
        int mx = -1;
        for(int i=0;i<x.second.size();i++){
            mx = max(mx,x.second[i]);
        }
        return mx;
    }
    return -1;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];

        cout << LargButMinFreq(arr, n) << endl;
    }
}  // } Driver Code Ends