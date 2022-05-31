// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        int n = S.size();
        if(n<2) return S;
        int sz = 1, start = 0;
        for(int i=0;i<n;i++){
            int lo = i-1, hi = i+1;
            while(hi<n && S[hi]==S[i])hi++;
            while(lo>-1 && S[lo]==S[i])lo--;
            while(lo>-1 && hi<n && S[lo]==S[hi]){
                lo--;hi++;
            }
            if(hi-lo-1>sz){
                sz = hi-lo-1;
                start = lo+1;
            }
        }
        return S.substr(start,sz);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends