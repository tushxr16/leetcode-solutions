// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        if(n>=q){
            return q-1;
        }else{
            long long ans = (2*n) - (q-1);
            if(ans<0)
                return 0;
            else
                return ans;
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}  // } Driver Code Ends