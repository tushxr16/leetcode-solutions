// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        vector<int> ind;
        int n = s1.size(), m = s2.size();
        if(n!=m)return false;
        for(int i=0;i<m;i++)
            if(s1[0]==s2[i])
                ind.push_back(i);

        for(int i=0;i<ind.size();i++){
            int tmp = 0;
            for(int j=0;j<m;j++){
                if(s2[(ind[i]+j)%m]==s1[j])
                    tmp++;
            }
            if(tmp==m)return true;
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}
  // } Driver Code Ends