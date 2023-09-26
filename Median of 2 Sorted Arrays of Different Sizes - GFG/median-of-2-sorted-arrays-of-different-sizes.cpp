//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        int i = 0, j = 0, k = 0, n = array1.size(), m = array2.size();
        vector<int> ans(n+m,0);
        while(i<n && j<m){
            if(array1[i]<array2[j]){
                ans[k++] = array1[i++];
            }else{
                ans[k++] = array2[j++];
            }
        }
        while(i<n){
            ans[k++] = array1[i++];
        }
        while(j<m){
            ans[k++] = array2[j++];
        }
        
        if((n+m)%2==0){
            return (double)(ans[(n+m)/2]+ans[(n+m)/2-1])/2.0;
        }else{
            return (double)ans[(n+m)/2];
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends