//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int arr[], int n, int k) {
        priority_queue<long long> pq;
        long long sum = 0;
        
        for(long long i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        while(!pq.empty() && k--){
            long long x = (pq.top());
            pq.pop();
            if(x/2!=0)
                pq.push(x/2);
            sum += x;
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends