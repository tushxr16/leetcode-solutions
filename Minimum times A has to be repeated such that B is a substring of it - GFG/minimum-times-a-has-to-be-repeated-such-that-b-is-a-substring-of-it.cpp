// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int minRepeats(string A, string B) {
        int ans = 1, flag = false;
        string T = A;
        while(T.size() <= 2*B.size()){
            if(T.find(B)!=string::npos){
                flag = true;
                break;
            }else{
                ans++;
                T=T+A;
            }
        }
        if(flag)return ans;
        else return -1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends