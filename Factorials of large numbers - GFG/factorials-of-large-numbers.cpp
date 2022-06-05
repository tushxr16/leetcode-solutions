// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        vector<int> ans(2569,0);
        ans[2568] = 1;
        for(int i=2;i<=N;i++){
            int carry = 0, len = 2569;
            while(len--){
                int tmp = ans[len]*i + carry;
                ans[len] = tmp%10;
                carry = tmp/10;
            }
        }
        while(ans[0]==0)ans.erase(ans.begin());
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends