// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long> st;
        vector<long long> left(n,0),right(n,01);
        long long ans = -1;
        for(int i=0;i<n;i++){
            if(st.empty()){
                left[i] = 0;
                st.push(i);
            }else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                left[i] = st.empty()?0:st.top()+1;
                st.push(i);
            }
        }
        
        while(!st.empty())
            st.pop();
        
        for(int i=n-1;i>-1;i--){
            if(st.empty()){
                right[i] = n-1;
                st.push(i);
            }else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                right[i] = st.empty()?n-1:st.top()-1;
                st.push(i);
            }
        }
        for(int i=0;i<n;i++){
            ans = max(ans,arr[i]*(right[i]-left[i]+1));
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends