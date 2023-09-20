//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    
    bool isNotAlpha(char c){
        if((c<='Z' && c>='A') || (c<='z' && c>='a'))
            return false;
        else
            return true;
    }
    
    string reverse(string str)
    { 
        int i = 0, j = str.size()-1, n = str.size();
        while(i<j){
            while(i<n && isNotAlpha(str[i])){
                i++;
            }
            while(j>-1 && isNotAlpha(str[j])){
                j--;
            }
            if(i>j) break;
            swap(str[i++],str[j--]);
        }
        return str;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.reverse(s) << endl;
    }
return 0;
}


// } Driver Code Ends