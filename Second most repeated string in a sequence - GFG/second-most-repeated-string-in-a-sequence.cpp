// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string,int> freq;
        for(int i=0;i<n;i++){
            if(freq.find(arr[i])==freq.end())
                freq[arr[i]] = 1;
            else
                freq[arr[i]]++;
        }
        pair<string,int> a={"",0},b={"",0};
        for(auto x:freq){
            if(x.second>b.second){
                if(x.second>=a.second){
                    b=a;
                    a=x;
                }else{
                    b=x;
                }
            }
        }
        return b.first;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends