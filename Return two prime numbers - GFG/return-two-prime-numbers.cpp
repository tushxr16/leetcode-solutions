//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> primeDivision(int N){
        bool prime[N + 1];
        memset(prime, true, sizeof(prime));
        for (int p = 2; p * p <= N; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= N; i += p)
                    prime[i] = false;
            }
        }
        for(int i=2;i<N/2+1;i++){
            if((prime[i]&prime[N-i])){
                return {i,N-i};
            }
        }
        return {-1,-1};
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends