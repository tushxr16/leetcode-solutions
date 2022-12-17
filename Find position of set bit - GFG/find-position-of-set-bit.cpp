//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        int cnt = 0, pos = -1, i = 0;
        while(N){
            i++;
            if(N%2){
                pos = i;
                cnt++;
            }
            N /= 2;
        }
        if(cnt>1){
            return -1;
        }else{
            return pos;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends