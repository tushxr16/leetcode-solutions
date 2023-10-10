//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        stack<int> st;
        vector<long long> ans(n);
        int i = n;
        while(i--){
            if(st.empty()){
                st.push(i);
                ans[i] = -1;
            }else{
                while(!st.empty() && arr[st.top()] <= arr[i]){
                    st.pop();
                }
                ans[i] = st.empty()? -1: arr[st.top()];
                st.push(i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends