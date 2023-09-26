//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    pair<int,int> min_max(vector<int> &bloomDay){
        int mn = INT_MAX, mx = INT_MIN;
        for(int day: bloomDay){
            mn = min(mn, day);
            mx = max(mx, day);
        }
        return {mn,mx};
    }
    
    bool isPossible(int mid, vector<int> &arr, int m, int k){
        int bouquets = 0, curr = 0, n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=mid){
                curr++;
            }else{
                curr = 0;
            }
            if(curr==k){
                curr = 0;
                bouquets++;
            }
        }
        return bouquets>=m;
    }
    int solve(int M, int K, vector<int> &bloomDay){
        pair<int,int> p = min_max(bloomDay);
        int ans = -1, lo = p.first, hi = p.second;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(isPossible(mid,bloomDay,M,K)){
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
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends