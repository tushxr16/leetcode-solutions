//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    vector<bool> vis(26,false);
    for(auto c: s){
        if(vis[c-'a']){
            string s = "";
            s.push_back(c);
            return s;
        }
        vis[c-'a'] = true;
    }
    return "-1";
}