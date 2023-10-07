//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int n, vector<int> &ratings) {
        int ans = 0;
        vector<int> candiesL(n,1), candiesR(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])
                candiesL[i] = candiesL[i-1] + 1;
            if(ratings[n-i-1]>ratings[n-i])
                candiesR[n-i-1] = candiesR[n-i] + 1;
        }
        for(int i=0;i<n;i++)
            ans += max(candiesL[i], candiesR[i]);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends