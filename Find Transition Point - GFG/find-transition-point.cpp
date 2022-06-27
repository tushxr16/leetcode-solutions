// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    int lo = 0, hi = n-1, mid, is = -1;
    while(lo<=hi){
        mid = (lo+hi)/2;
        if(arr[mid]==1){
            hi = mid-1;
            is = mid;
        }
        else
            lo = mid+1;
    }
    return is;
}