// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    
    string modify (string s)
    {
        bool cap = true;
        if(s[0]>='a')
            cap = false;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(cap){
                if(s[i]>='a')
                    s[i] = s[i]-'a'+'A';
            }else{
                if(s[i]<'a')
                    s[i] = s[i]-'A'+'a';
            }
        }
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.modify (s) << endl;
	}
}  // } Driver Code Ends