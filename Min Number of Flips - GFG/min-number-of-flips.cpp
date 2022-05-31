// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string S)
{
    int ans1 = 0, ans2 = 0, n = S.size();
    for(int i=0;i<n;i++){
        if(i&1){
            if(S[i]=='1') ans2++;
            else ans1++;
        }else{
            if(S[i]=='1') ans1++;
            else ans2++;
        }
    }
    return n - max(ans1,ans2);
    
}