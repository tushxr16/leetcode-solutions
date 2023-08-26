//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int,vector<int>> mp1, mp2;
        
        for(int i=0;i<2*e;i+=2){
            mp1[A[i]].push_back(A[i+1]);
            mp2[B[i]].push_back(B[i+1]);
        }
        
        for(pair<int,vector<int>> p: mp1){
            vector<int> a = p.second;
            vector<int> b = mp2[p.first];
            int n = a.size(), m = b.size();
            if(n!=m) return 0;
            for(int i=0;i<n;i++){
                if(a[i]!=b[n-i-1]) return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends