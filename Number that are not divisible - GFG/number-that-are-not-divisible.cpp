// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    long long noOfNumbers(long long N) {
        long long ans = N - N/2 - N/3 - N/5 - N/7 + N/6 + N/10 + N/14 + N/15 + N/21 + N/35 -
        N/30 - N/105 - N/70 - N/42 + N/210;
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.noOfNumbers(N) << endl;
    }
    return 0;
}  // } Driver Code Ends