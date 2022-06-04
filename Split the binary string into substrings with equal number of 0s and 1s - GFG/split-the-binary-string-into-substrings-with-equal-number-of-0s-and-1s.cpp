// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxSubStr(string s){
        int ans = 0, one = 0, zero = 0, n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                one++;
            }else zero++;
            if(one==zero){
                ans++;
            }
        }
        if(one!=zero)
            return -1;
        else return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends