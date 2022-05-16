// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        int cnt=0,pos=0,i=1;
        while(N>0){
            cnt+=(N%2);
            if(N%2==1)
                pos=i;
            N/=2;
            i++;
        }
        if(cnt!=1)return -1;
        else return pos;
    }
};

// { Driver Code Starts.
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
}  // } Driver Code Ends