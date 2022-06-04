// { Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int n = str1.size(), m = str2.size();
        if(n!=m)return false;
        int c[256], d[256];
        for(int i=0;i<256;i++){
          c[i]=d[i]=0;  
        }
        for(int i=0;i<n;i++){
            c[str1[i]-'a']++;
            d[str2[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            if(c[str1[i]-'a']!=d[str2[i]-'a'])return false;  
        }
        return true;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends