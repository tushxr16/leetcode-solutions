// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

class Solution{
    public:
    string removeConsecutiveCharacter(string s)
    {
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                s.erase(i,1);
                i--;
            }
        }
        return s;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends