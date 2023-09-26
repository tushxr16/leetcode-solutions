//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxOfPiles(vector<int> &piles, int n){
        int mx = INT_MIN;
        for(int x: piles){
            mx = max(mx, x);
        }
        return mx;
    }
    
    int isPossible(int mid, vector<int> &piles, int n, int h){
        int hours = 0;
        for(int i=0;i<n;i++){
            hours += (int)ceil((double)piles[i]/(double)mid);
        }
        return hours<=h;
    }
    
    int Solve(int N, vector<int>& piles, int H) {
        int lo = 1, hi = maxOfPiles(piles,N), ans = -1;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(isPossible(mid,piles,N,H)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends