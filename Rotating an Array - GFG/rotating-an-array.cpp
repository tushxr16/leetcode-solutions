// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void leftRotate(int arr[], int n, int d) {
        for(int i=0;i<d/2;i++)
            swap(arr[i],arr[d-i-1]);
        for(int i=0;i<(n-d)/2;i++)
            swap(arr[i+d],arr[n-1-i]);
        for(int i=0;i<n/2;i++)
            swap(arr[i],arr[n-1-i]);
        return;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> d;
        Solution ob;
        ob.leftRotate(arr, n, d);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}


  // } Driver Code Ends