// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        set<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int lo = j+1, hi = n-1;
                while(lo<hi){
                    int temp_sum = arr[i]+arr[j]+arr[lo]+arr[hi];
                    if(temp_sum>k){
                        hi--;
                    }else if(temp_sum<k){
                        lo++;
                    }else{
                        ans.insert({arr[i],arr[j],arr[lo],arr[hi]});
                        lo++;
                        hi--;
                    }
                }
            }
        }
        vector<vector<int>> ret(ans.begin(),ans.end());
        return ret;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends