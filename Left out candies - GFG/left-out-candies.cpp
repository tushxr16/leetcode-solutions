//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long leftCandies(long long n, long long m);

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        auto ans = leftCandies(n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends


long long leftCandies(long long n, long long m) {
    long long all = n*(n+1)/2;
    m = m%all;
    long long x = (sqrt(1+8*m) - 1)/2;
    m = m - (x*(x+1)/2);
    return m;
}