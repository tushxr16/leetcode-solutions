// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        unordered_map<char,int> mp;
        int n = a.size();
        if(n!=b.size())
            return false;
        for(int i=0;i<n;i++)
            mp[a[i]]++;
        for(int i=0;i<n;i++){
            if(mp.find(b[i])==mp.end()){
                return false;
            }else{
                if(mp[b[i]]==1){
                    mp.erase(b[i]);
                }else{
                    mp[b[i]]--;
                }
            }
        }
        return true;
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends